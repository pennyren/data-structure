#include <stdio.h>

int main() {
    int year, n;
    while (scanf("%d %d", &year, &n) != EOF) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
        days[1] = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28;
        int sum = 0, month, day, i;

        for (i = 0; i < 12; i++) {
            if (sum >= n) break;
            sum = sum + days[i];
        }
        month = i;
        day = n - (sum - days[i - 1]);
        //0无符号，2/4位数，注意格式控制符
        printf("%04d-%02d-%02d\n", year, month, day);
    }
}
