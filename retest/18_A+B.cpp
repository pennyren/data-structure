#include <stdio.h>

int getNum(char *p) {
    int isNegative = 0, num = 0;
    if (*p == '-') {
        isNegative = 1;
        p++;
    }
    while (*p) {
        if (*p != ',') {
            num = num * 10 + (*p - '0');
        }
        p++;
    }
    return isNegative ? -num : num;
}

int main() {
    char a[15], b[15];
    while (scanf("%s %s", a, b) != EOF) {
        printf("%d\n", getNum(a) + getNum(b));
    }
    return 0;
}
