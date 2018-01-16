#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left, *right;
} BinaryTreeNode, *BST;

//此处T要用&，否则就是简单的值传递。
void insertBST(BST &T, BinaryTreeNode *parent, int el) {
    if (T == NULL) {
        T = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        T->data = el;
        T->left = T->right = NULL;
        (parent != NULL) ? printf("%d\n", parent->data) : printf("-1\n");
    } else if (el < T->data) {
        insertBST(T->left, T, el);
    } else {
        insertBST(T->right, T, el);
    }
}

int main() {
    int n, el;
    while (scanf("%d", &n) != EOF) {
        BST T = NULL;
        while (n--) {
            scanf("%d", &el);
            insertBST(T, NULL, el);
        }
    }
    return 0;
}
