#include <stdio.h>

int main() {
    int n, num[1000];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; j > i; j--) {
                if (num[j - 1] > num[j]) {
                    int temp = num[j];
                    num[j] = num[j - 1];
                    num[j - 1] = temp;
                }
            }
        }
        printf("%d\n", num[n - 1]);
        //只有一个元素情形
        if (n == 1) {
            printf("-1\n");
        } else {
            for (int i = 0; i < n - 2; i++) {
                printf("%d ", num[i]);
            }
            //最后一个元素为无空格，直接换行
            printf("%d\n", num[n-2]);
        }
    }
    return 0;
}
