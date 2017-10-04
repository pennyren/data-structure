#ifndef __UTILS_H
#define __UTILS_H

#include <stdlib.h>

#define true 1
#define false 0
#define arrayLength(a) (sizeof(a) / sizeof(*a))

#define maxSize 20

typedef enum {array, list, stack, queue, tree, graph} structdef;
typedef int boolean;

//-------------------SqList--------------------//
//静态分配
typedef struct {
	int data[maxSize];
	int length;
}SqList;

//动态分配
typedef struct {
	int *data;
	int length;
}SeqList;

SqList initSqList(int A[], int length) {
    SqList L;
    L.length = length;
    int pos = 0;
    while (pos < length) {
        L.data[pos] = A[pos];
        pos++;
    }
    return L;
}


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
	//尾插法，输入顺序与构造出的链表一致，附设尾指针
	while(el != -1) {
		LNode *node = (LNode*)malloc(sizeof(LNode));
        node->data = el;
        r->next = node;
        r = node;
        scanf("%d", &el);
	}
	r->next = NULL;
	return L;
	//头插法，输入顺序与结果链表逆序
	//node->next = L->next;L->next = node;
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

//--------------SqStack--------------------//
typedef struct {
    int data[maxSize];
    int top;
}SqStack;

void initStack(SqStack &s) {
    s.top = -1;
}

boolean isEmptyStack(SqStack &s) {
    return (s.top == -1) ? true : false;
}

boolean push(SqStack &s, int el) {
    if (s.top == maxSize - 1) return false;
    s.data[++s.top] = el;
    return true;
}

int pop(SqStack &s) {
    return (s.top == -1) ? false : s.data[s.top--];
}

//----------------SqQueue-------------------//
typedef struct {
    int data[maxSize];
    int front, rear;
}SqQueue;

void initQueue(SqQueue &q) {
    q.front = q.rear = 0;
}

boolean isEmptyQueue(SqQueue &q) {
    return (q.front == q.rear) ? true : false;
}

boolean enQueue(SqQueue &q, int el) {
    if ((q.rear + 1) % maxSize == q.front) return false;
    q.data[q.rear] = el;
    q.rear = (q.rear + 1) % maxSize;
    return true;
}

int deQueue(SqQueue &q) {
    int el;
    if (q.front == q.rear) return false;
    el = q.data[q.front];
    q.front = (q.front + 1) % maxSize;
    return el;
}



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

//“2134” => 2134
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
