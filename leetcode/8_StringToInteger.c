/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Solution:
1. discards all leading whitespaces
2. sign of the number
3. overflow return MAX
4. invalid input return 0

INT_MIN	-32767
INT_MAX	+32767
*/

#include <stdio.h>
#include <limits.h>

int myAtoi(char* str) {
    int i = 0, base = 0, isNegative;
    while (str[i] == ' ') i++;
    isNegative = str[i] == '-' ? 1 : 0;

    if (str[i] == '-' || str[i] == '+') i++;
    while (str[i] >= '0' && str[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            return isNegative ? INT_MIN : INT_MAX;
        }
        base = base * 10 + (str[i++] - '0');
    }
    
    return isNegative ? -base : base;
}

int main() {
    char str[] = "-1231241";
    printf("%d", myAtoi(str));
    return 0;
}