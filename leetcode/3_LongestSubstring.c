/*
Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    char sub[100] = {'\0'};
    int maxlen = 0, c = 0, i;

    while (*s) {
        i = 0;
        sub[c] = *s; sub[++c] = '\0';    
        while (i < c - 1) {            
            //make behind i elements forward move i position
            if (sub[i] == *s) {
                i++; c = c - i;
                for (int j = 0; j < c; j++) {
                    sub[j] = sub[i++];
                }             
                break;
            }
            i++;
        }
        maxlen = c > maxlen ? c : maxlen;
        s++;
    }
    return maxlen;
}

int main() {
    char str[] = "abcabcbb";
    printf("%d", lengthOfLongestSubstring(str));
    return 0;
}
