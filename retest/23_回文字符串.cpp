#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    while (scanf("%s", str) != EOF) {
        int i = 0, j = strlen(str) - 1;
        int isPalindrome = 0;
        while (i != j && (j - i) != 1) {
            if (str[i] != str[j]) {
                break;
            }
            i++; j--;
        }
        if (i == j || str[i] == str[j]) {
            isPalindrome = 1;
        }
        isPalindrome ? printf("Yes!\n") : printf("No!\n");
    }
    return 0;
}
