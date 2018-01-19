#include <stdio.h>
#include "tree.h"

void inOrder(BiTree T);
void preOrder(BiTree T);
void inOrderByStack(BiTree T);
void postOrderByStack(BiTree T);
void levelOrder(BiTree T);
int depth(BiTree T);
int _depth(BiTree T);

int main() {
    //重点为后序遍历栈方式、层次遍历、递归遍历
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
    printf("\n");
    printf("Post Order by Stack: ");
    postOrderByStack(T);
    printf("\n");
    int dep = depth(T);
    printf("Tree Depth: %d", dep);
    return 0;
}

//使用递归遍历二叉树，栈的深度与树的深度一致
void inOrder(BiTree T) {
    //中序
    if (T) {
        inOrder(T->lchild);
        printf("%d ", T->data);
        inOrder(T->rchild);
    }
}

void preOrder(BiTree T) {
    //先序
    if (T) {
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
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

//后序遍历非递归算法
//特性，当访问节点p时，栈中节点恰好是p的祖先节点
//即从根节点(栈底)到p节点的一条路径
void postOrderByStack(BiTree T) {
    BTStack s;
    initBTStack(s);
    //分清返回根节点是从左子树还是右子树
    //使用visited来指向最近访问过的节点
    BiTNode *p = T, *visited = NULL;
    while (p || !isEmptyBTStack(s)) {
        if (p) {
            push(s, p);
            p = p->lchild;
        } else {
            p = getTop(s);
            //右子树存在且未被访问过
            if (p->rchild && p->rchild != visited) {
                p = p->rchild;
                push(s, p);
                //再走向最左
                p = p->lchild;
            } else { //弹出节点信息
                pop(s, p);
                printf("%d ", p->data);
                visited = p;
                p = NULL; //节点访问完后，重置p指针
            }
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

//使用层次遍历求解二叉树的高度
//使用last指向当前层最右节点，每次出队时与last指针比较
//若两者相等，层数加一，并让last指向下一层最右节点
int depth(BiTree T) {
    if (!T) return 0;
    //指示
    int last = 0, level = 0;
    //队列初始化
    BiTree que[100];
    int front = -1, rear = -1;
    que[++rear] = T; //根节点入队
    BiTree p;
    //队列不空，则循环
    while (front < rear) {
        //出队
        p = que[++front];
        //入队
        if (p->lchild) que[++rear] = p->lchild;
        if (p->rchild) que[++rear] = p->rchild;
        //处理该层最右节点
        if (front == last) {
            level++;
            last = rear;
            //该层节点数 printf("%d ", rear - front);
            //遍历最后一层完时front == rear，
        }
    }
    return level;
}

//递归求高度
int _depth(BiTree T) {
    int ldep, rdep;
    if (!T) return 0;
    ldep = _depth(T->lchild);
    rdep = _depth(T->rchild);
    return ldep > rdep ? ldep + 1 : rdep + 1;
}

//插入的节点一定是某个叶子节点
boolean insertBST(BiTree T, int el) {
    if (T == NULL) {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = el;
        T->lchild = T->rchild = NULL;
        return true;
    } else if (el == T->data) {
        return false;
    } else if (el < T->data) {
        return insertBST(T->lchild, el);
    } else {
        return insertBST(T->rchild, el);
    }
}

void createBST(BiTree T) {
    int el;
    scanf("%d", &el);
    while (el != -1) {
        insertBST(T, el);
    }
}

BiTNode *searchBST(BiTree T, int el) {
    BiTNode *p = NULL;
    while (T != NULL && el != T->data) {
        //p指向被查找节点的双亲，用于插入和删除操作
        p = T;
        el < T->data ? (T = T->lchild) : (T = T->rchild);
    }
    return T;
}
