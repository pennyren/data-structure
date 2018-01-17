#include <stdio.h>

int main() {
    int m, n, matrix[100][100];
    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {
            int max = matrix[i][0], index = 0, sum = 0;
            for (int j = 0; j < n; j++) {
                sum = sum + matrix[i][j];
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                    index = j;
                }
            }
            matrix[i][index] = sum;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("%d\n", matrix[i][n - 1]);
        }
    }
    return 0;
}
