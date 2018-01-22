/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)
P     A     H     N
 A  P  L  S  I  I   G
  Y     I     R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s) + 1, i = 0, j = 0, k = 0, isDecline = 0;
    char matrix[numRows][n];
    char *str = (char *)malloc(sizeof(char) * n);
    if (numRows == 1) {
        return s;
    }

    // matrix initialization
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = '\0';
        }
    }

    // store zigzag string in matrix
    i = j = 0;
    while (*s) {
        matrix[i][j++] = *s;
        if (i == numRows - 1) {
            isDecline = 1;
        }
        if (i == 0) {
            isDecline = 0;
        }
        isDecline ? i-- : i++;
        s++;
    }

    // get line string
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != '\0') {
                str[k++] = matrix[i][j];
            }
        }
    }
    str[k] = '\0';
    return str;
}

int main() {
    char str[] = "PAYPALISHIRING";
    printf("%s", convert(str, 3));
    return 0;
}
