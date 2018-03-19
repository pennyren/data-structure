/*
Determine whether an integer is a palindrome. Do this without extra space.

1. < 0 
2. handle big number 
*/
#include <stdio.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int revertedNumber = 0, temp = x;
    while (x != 0) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    return temp == revertedNumber;
}

int main() {
    printf("%d", isPalindrome(1));
    return 0;
}
