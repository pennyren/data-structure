#include <stdio.h>
#include "utils.h"

//-----------CharList-------------//
typedef struct CNode{
	char data;
	struct CNode *next;
}CNode, *CharList;

CharList createCharList() {
	char el;
    CharList L = (CharList)malloc(sizeof(CNode));
	CNode *r = L;
	L->next = NULL;
	scanf("%c", &el);
	while(el != 'q') {
		CNode *p = (CNode*)malloc(sizeof(CNode));
		p->data = el;
        r->next = p;
		r = p;
        scanf("%c", &el);
	}
	r->next = NULL;
	return L;
}

int length(CharList L) {
    int i = 0;
    CNode *p = L->next;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

void print(CharList L, int len) {
	CNode *p = L->next, *q;
	if (len > 1) {
        printf("[%c -> ", p->data);
        p = p->next;
        while (p) {
            q = p->next;
            q ? printf("%c -> ", p->data) : printf("%c]\n", p->data);
            p = q;
        }
	} else if (len == 1) {
	     printf("[%c]\n", p->data);
	} else {
	     printf("[]\n");
	}
}

//-------------------CharStack---------------//
typedef struct {
    char data[maxSize];
    int top;
}CharStack;

void initCharStack(CharStack &s) {
    s.top = -1;
}

boolean isEmptyCharStack(CharStack &s) {
    return (s.top == -1) ? true : false;
}

boolean pushChar(CharStack &s, int el) {
    if (s.top == maxSize - 1) return false;
    s.data[++s.top] = el;
    return true;
}

int popChar(CharStack &s) {
    return (s.top == -1) ? false : s.data[s.top--];
}

//-----------------Method-----------------------//

boolean isCentralSymmetry(CharList L, int n);
boolean isMatchedBrackets(char *str);
int recursionByStack(int n, int x);

int main() {
    //xyzyxq
    CharList L = createCharList();
    char *test = "[{]}]";
    printf("Origin: ");
    print(L, length(L));
    printf("isCentralSymmetry: %d\n", isCentralSymmetry(L, length(L)));
    printf("isMatchedBrackets: %d\n", isMatchedBrackets(test));
    printf("Final recursion value: %d", recursionByStack(20, 2));
    return 0;
}

//判断字符串链是否中心对称，如xyx,xyyx
//使用栈，扫描前半部分时入栈，后半部分则与栈顶元素比较，相等则出栈。
//注意输入时候空格也是一个字符。
boolean isCentralSymmetry(CharList L, int n) {
    char elStack[n/2]; //字符栈
    int top = -1;
    CNode *p = L->next;
    for (int i = 0; i < n/2; i++) {
        elStack[++top] = p->data;
        p = p->next;
    }

    (n % 2 == 1) && (p = p->next);

    while (p && elStack[top] == p->data) {
        top--;
        p = p->next;
    }
    return (top == -1) ? true : false;
}

//检测括号[]{}()是否匹配，利用栈，贪心算法。
boolean isMatchedBrackets(char *str) {
    CharStack s;
    initCharStack(s);
    int i = 0;
    char el;
    while (str[i]) {
        switch (str[i]) {
            case '(':
                pushChar(s, '('); break;
            case '[':
                pushChar(s, '['); break;
            case '{':
                pushChar(s, '{'); break;
            case ')':
                el = popChar(s);
                if (el != '(') return false;
                break;
            case ']':
                el = popChar(s);
                if (el != '[') return false;
                break;
            case '}':
                el = popChar(s);
                if (el != '{') return false;
                break;
            default:
                break;
        }
        i++;
    }
    return isEmptyCharStack(s) ? true : false;
}

//使用栈模拟递归函数的非递归运算
//栈的大小与递归次数一致，栈顶(或栈底)为递归出口(基本情形)
int recursionByStack(int n, int x) {
    int stack[n + 1];
    int top = -1;
    while (++top < (n + 1)) {
        if (top == 0) {
            stack[top] = 1;
        } else if (top == 1) {
            stack[top] = 2 * x;
        } else {
            stack[top] = 2 * x * stack[top - 1] - 2 * (top - 1) * stack[top - 2];
        }
    }
    return stack[top];
}
