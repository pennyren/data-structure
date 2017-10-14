#include <stdio.h>

void getNext(char pattern[], int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while(i <= pattern[0]) {
        if(j == 0 || pattern[i] == pattern[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int KMP(char text[], char pattern[], int next[], int pos) {
    int i = pos; j = 1;
    while (i <= text[0] && j <= pattern[0]) {
        if ( j == 0 || text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    return j > pattern[0] ? i - pattern[0] : 0;
}

int main() {
    return 0;
}
