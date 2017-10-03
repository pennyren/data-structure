#ifndef __UTILS_H
#define __UTILS_H

#include <stdlib.h>

#define true 1
#define false 0
#define arrayLength(a) (sizeof(a) / sizeof(*a))

typedef enum {array, list, stack, queue, tree, graph} structdef;
typedef int boolean;

//--------------------LinkList---------------//
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList createList() {
	int el;
    LinkList L = (LinkList)malloc(sizeof(LNode));
	LNode *r = L;
	L->next = NULL;
	scanf("%d", &el);
	while(el != -1) {
		LNode *node = (LNode*)malloc(sizeof(LNode));
        node->data = el;
        r->next = node;
        r = node;
        scanf("%d", &el);
	}
	r->next = NULL;
	return L;
}

int listLength(LinkList L) {
    int i = 0;
    LNode *p = L->next;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

//-----------------------------------------//

//--------------utils----------------------//
void printArray(int *arr, int len) {
    int pos = 0;
    if (len > 1) {
        while (pos < len) {
            if (pos == 0) {
                printf("[%d, ", arr[pos]);
            } else if (pos == len - 1) {
                printf("%d]\n", arr[pos]);
            } else {
                printf("%d, ", arr[pos]);
            }
            pos++;
        }
    } else if (len == 1) {
        printf("[%d]\n", arr[0]);
    } else {
        printf("[]\n");
    }
}

void printList(LinkList L, int len) {
	LNode *p = L->next, *q;
	if (len > 1) {
        printf("[%d -> ", p->data);
        p = p->next;
        while (p) {
            q = p->next;
            q ? printf("%d -> ", p->data) : printf("%d]\n", p->data);
            p = q;
        }
	} else if (len == 1) {
	     printf("[%d]\n", p->data);
	} else {
	     printf("[]\n");
	}
}

int toNumber(char a[]) {
    int sign, offset, num = 0;

    sign = (a[0] == '-') ? -1 : 1;
    offset = (sign == -1) ? 1 : 0;

    while (a[offset] != '\0') {
        num = num * 10 + a[offset] - '0';
        offset++;
    }

    return sign == 1 ? num : -num;
}

#endif
