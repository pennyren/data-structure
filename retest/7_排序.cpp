#include <stdio.h>

int main() {
    int n, num[100], min, temp;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }

        //选择排序
        for (int i = 0; i < n; i++) {
            min = i;
            for (int j = i + 1; j < n; j++) {
                if (num[j] < num[min]) min = j;
            }
            if (min != i) {
                temp = num[i];
                num[i] = num[min];
                num[min] = temp;
            }
        }
        
        for (int i = 0; i < n; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
    }
    return 0;
}
