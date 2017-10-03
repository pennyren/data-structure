#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int boolean;

typedef struct LNode{
	char data;
	struct LNode *next;
}LNode, *LinkList;


boolean isCentralSymmetry(LinkList &L, int n);

LinkList createList() {
	char el;
    LinkList L = (LinkList)malloc(sizeof(LNode));
	LNode *r = L;
	L->next = NULL;
	scanf("%c", &el);
	while(el != 'q') {
		LNode *node = (LNode*)malloc(sizeof(LNode));
		node->data = el;
        r->next = node;
		r = node;

        scanf("%c", &el);
	}
	return L;
}

int main() {
    LinkList L = createList();
    int result = isCentralSymmetry(L, 6);
    printf("isCentralSymmetry: %d", result);
    return 0;
}

//判断字符串链是否中心对称，如xyx,xyyx
//使用栈，扫描前半部分时入栈，后半部分则与栈顶元素比较，相等则出栈。
//注意输入时候空格也是一个字符。
boolean isCentralSymmetry(LinkList &L, int n) {
    char elStack[n/2]; //字符栈
    int top = -1;
    LNode *p = L->next;
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
