#include <stdio.h>

// math.h
// 绝对值 double fabs(double x)
// 不大于x的最大整数 double floor(double x)
// 指数 double pow(double x, double y)

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int sum(int start, int end) {
    int c = 0;
    while (start <= end) {
        c = c + factorial(start);
        start = start + 2;
    }
    return c;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int isOddNumber = n % 2 != 0;
        int oddEnd = isOddNumber ? n : n - 1;
        int evenEnd = isOddNumber ? n - 1 : n;
       printf("%d %d\n", sum(1, oddEnd), sum(2, evenEnd));
    }
    return 0;
}
