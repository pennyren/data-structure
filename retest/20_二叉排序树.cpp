#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left, *right;
} BinaryTreeNode, *BST;

int insertBST(BST &T, int el) {
    if (T == NULL) {
        T = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        T->data = el;
        T->left = T->right = NULL;
        return 1;
    } else if (el == T->data) {
        return 0;
    } else if (el < T->data) {
        return insertBST(T->left, el);
    } else {
        return insertBST(T->right, el);
    }
}

void preOrder(BST T) {
    if (T) {
        printf("%d ", T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}

void inOrder(BST T) {
    if (T) {
        inOrder(T->left);
        printf("%d ", T->data);
        inOrder(T->right);
    }
}

void postOrder(BST T) {
    if (T) {
        postOrder(T->left);
        postOrder(T->right);
        printf("%d ", T->data);
    }
}

int main() {
    int n, el;
    while (scanf("%d", &n) != EOF) {
        BST T = NULL;
        while (n--) {
            scanf("%d", &el);
            insertBST(T, el);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}
