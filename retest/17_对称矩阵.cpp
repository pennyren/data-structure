#include <stdio.h>

int main() {
    int n, matrix[100][100];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        int isSymmetric = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    isSymmetric = 0;
                    break;
                }
            }
        }
        isSymmetric ? printf("Yes!\n") : printf("No!\n");
    }
    return 0;
}
