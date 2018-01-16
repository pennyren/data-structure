#include <stdio.h>

//直接打印后序序列无需构造二叉树
void printPostOrder(char pre[], char in[], int n) {
    int root;
    //中序中查找左右子树的根
    for (int i = 0; i < n; i++) {
        if (in[i] == pre[0]) root = i;
    }
    //中序左子树非空
    if (root != 0) {
        printPostOrder(pre + 1, in, root);
    }
    //中序右子树非空
    if (root != n - 1) {
        printPostOrder(pre + root + 1, in + root + 1, n - root - 1);
    }
    printf("%c", pre[0]);
}

int main() {
    char pre[27], in[27];
    while (scanf("%s %s", pre, in) != EOF) {
        int n = 0;
        char *p = in;
        while (*p) {
            p++; n++;
        }
        printPostOrder(pre, in, n);
        printf("\n");
    }
    return 0;
}
