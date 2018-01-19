#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    while (scanf("%s", str) != EOF) {
        int i = 0, j = strlen(str) - 1;
        int isPalindrome = 1;
        while (i != j && (j - i) != 1) {
            if (str[i] != str[j]) {
                isPalindrome = 0;
                break;
            }
            i++; j--;
        }
        isPalindrome ? printf("Yes!\n") : printf("No!\n");
    }
    return 0;
}
