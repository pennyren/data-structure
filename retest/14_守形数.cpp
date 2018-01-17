#include <stdio.h>

int main() {
    int num;
    while (scanf("%d", &num) != EOF) {
        int a = num % 10, b = num / 10, c = num * num;
        if (b) {
            a == c % 10 && b == (c / 10) % 10 ? printf("Yes!\n") : printf("No!\n");
        } else {
            a == c % 10 ? printf("Yes!\n") : printf("No!\n");
        }
    }
    return 0;
}
