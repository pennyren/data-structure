#include <stdio.h>
#include "utils.h"

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

boolean isCentralSymmetry(CharList L, int n);

int main() {
    CharList L = createCharList();
    printf("isCentralSymmetry: %d", isCentralSymmetry(L, length(L)));
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
