#ifndef __UTILS_H
#define __UTILS_H

#include <stdlib.h>

#define true 1
#define false 0
#define maxSize 20

typedef int boolean;

//----------------------BiTree---------------------//
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//按先序序列输入节点值，-1代表空树
void createBiTree(BiTree &T) {
    int el;
    scanf("%d", &el);
    if (el == -1) {
        T = NULL;
    } else {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = el;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}

void printTree(BiTree T) {

}

//-------------------BTStack---------------//
typedef struct {
    BiTNode *data[maxSize];
    int top;
}BTStack;

void initBTStack(BTStack &s) {
    s.top = -1;
}

boolean isEmptyBTStack(BTStack &s) {
    return (s.top == -1) ? true : false;
}

boolean push(BTStack &s, BiTNode *el) {
    if (s.top == maxSize - 1) return false;
    s.data[++s.top] = el;
    return true;
}

boolean pop(BTStack &s, BiTNode* &el) {
    if (s.top == -1) {
        return false;
    } else {
        el = s.data[s.top--];
        return true;
    }
}
BiTNode* getTop(BTStack &s) {
    return s.data[s.top];
}

//----------------BTQueue-------------------//
typedef struct {
    BiTNode *data[maxSize];
    int front, rear;
}BTQueue;

void initBTQueue(BTQueue &q) {
    q.front = q.rear = 0;
}

boolean isEmptyBTQueue(BTQueue &q) {
    return (q.front == q.rear) ? true : false;
}

boolean enQueue(BTQueue &q, BiTNode *el) {
    if ((q.rear + 1) % maxSize == q.front) return false;
    q.data[q.rear] = el;
    q.rear = (q.rear + 1) % maxSize;
    return true;
}

boolean deQueue(BTQueue &q, BiTNode* &el) {
    if (q.front == q.rear) {
        return false;
    } else {
        el = q.data[q.front];
        q.front = (q.front + 1) % maxSize;
        return true;
    }
}

#endif
