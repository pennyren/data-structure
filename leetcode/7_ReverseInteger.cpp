/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output:  321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range.
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <stdio.h>

int reverse(int x) {
    int num = 0;
    while (x != 0) {
        int temp = num * 10 + x % 10;
        // check for integer overflow, compare with previous number;
        if (temp / 10 != num) {
            return 0;
        }
        // x sign is same with x % 10
        num = temp;
        x = x / 10;
    }
    return num;
}

int main() {
    int num = -321;
    printf("%d", reverse(num));
    return 0;
}