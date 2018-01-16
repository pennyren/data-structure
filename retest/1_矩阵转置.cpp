#include <stdio.h>
int main() {
    int n, matrix[100][100];
    // 多组测试数据
    // EOF表示文件流的结尾或标准输入的结尾
    
    while (scanf("%d", &n) != EOF) {
        // 输入矩阵，录入过程中转置
        // 转置，实质为除对角线外，i，j序号交换
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &matrix[j][i]);
            }
        }

        // 输出, 每行需保证最后一个元素之后为换行，而非空格
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("%d\n", matrix[i][n - 1]);
        }
    }
    return 0;
}
