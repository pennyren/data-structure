#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
#define true 1
#define false 0
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

//----------------Queue-------------------//
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

//---------------Method-----------------//
void inOrderByStack(BiTree T);
void levelOrder(BiTree T);
void inOrder(BiTree T);

int main() {
    BiTree T;
    //先序序列输入2 3 -1 6 -1 -1 7 8 -1 -1 9 -1 -1
    createBiTree(T);
    printf("In Order by Recursion: ");
    inOrder(T);
    printf("\n");
    printf("In Order by Stack: ");
    inOrderByStack(T);
    printf("\n");
    printf("Level Order: ");
    levelOrder(T);
    return 0;
}

//使用递归遍历二叉树，栈的深度与树的深度一致
//中序遍历
void inOrder(BiTree T) {
    if (T) {
        inOrder(T->lchild);
        printf("%d ", T->data);
        inOrder(T->rchild);
    }
}

//借助栈的中序非递归算法
//1. 从根开始依次扫描左孩子并入栈，直到最左端。
//2. 出栈，并访问出栈节点，扫描该节点右孩子并进栈。
//3. 扫描右孩子的左孩子一一入栈，直到最左端。
//4. 重复2、3
void inOrderByStack(BiTree T) {
    BTStack s;
    initBTStack(s);
    BiTNode *p = T;
    while (p || !isEmptyBTStack(s)) {
        if (p) {
            //直到左孩子最左端，且以先序序列入栈。
            push(s, p);
            p = p->lchild;
        } else {
            //出栈并访问节点，且中序序列出栈。
            pop(s, p);
            printf("%d ", p->data);
            //指向右孩子，并继续开始遍历其左孩子。
            p = p->rchild;
        }
    }
}

//层次遍历，使用队列
void levelOrder(BiTree T) {
    BTQueue q;
    initBTQueue(q);
    BiTNode *p;
    enQueue(q, T);
    while (!isEmptyBTQueue(q)) {
        deQueue(q, p);
        printf("%d ", p->data);
        if (p->lchild) enQueue(q, p->lchild);
        if (p->rchild) enQueue(q, p->rchild);
    }
}
