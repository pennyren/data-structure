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

    return 1;
}

int main() {
    return 0;
}
