/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"

Note: "aba" is also a valid answer.

Example:
Input: "cbbd"
Output: "bb"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//max slide window method
char* longestPalindrome(char* s) {
    char *sub = (char *)malloc(sizeof(char) * 1000);
    int len = strlen(s), window = len;
    while (window) {
        int start = 0, end = window - 1, slide = len - window;
        int i, j;
        while (start <= slide) {
            i = start, j = end;
            //check if current substring is palindrome
            while (i != j && (j - i) != 1) {
                if (s[i] != s[j]) {
                    break;
                }
                i++; j--;
            }
           
            if (i == j || s[i] == s[j]) {
                int k = 0;
                while (start <= end) {
                    sub[k++] = s[start++];
                }
                sub[k] = '\0';
                return sub;
            }
            start++; end++;
        }
        window--;
    }
    return sub;  
}

int main() {
    char str[] = "cbbd";
    printf("%s", longestPalindrome(str));
    return 0;
}