#include <stdio.h>

void decToOctal(int n) {
    int oct[7], i = 0, c = 0;
    while (n > 0) {
        oct[i++] = n % 8;
        n = n / 8;
        c++;
    }
    while (--c) {
        printf("%d", oct[c]);
    }
    printf("%d\n", oct[0]);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        decToOctal(n);
    }
    return 0;
}
