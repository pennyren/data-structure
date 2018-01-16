#include <stdio.h>
int main() {
    int n, matrix[4][5];
    scanf("%d", &n);
    for (int c = 0; c < n; c++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int max[2];
        for (int i = 0; i < 5; i++) {
            max[0] = matrix[0][i];
            max[1] = matrix[1][i];
            for (int j = 2; j < 4; j++) {
                //不能取大于等于
                if (matrix[j][i] > max[0] || matrix[j][i] > max[1]) {
                    max[0] = (max[0] > max[1]) ? max[0] : max[1];
                    max[1] = matrix[j][i];
                }
            }
            matrix[0][i] = max[0];
            matrix[1][i] = max[1];
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("%d \n", matrix[i][4]);
        }
    }
    return 0;
}
