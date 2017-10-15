#include <stdio.h>
#include "utils.h"

void getNext(char pattern[], int next[], int plen) {
    next[0] = -1;
    int i = 0, j = -1;
    
    while(i < plen) {
        if(j == -1 || pattern[i] == pattern[j]) {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }
}

//i,j分别为text与pattern指针，匹配过程中出现字符比较不等时
//i不需回溯指针，而是利用已经得到的部分匹配结果，将pattern
//尽可能远的向右滑动一段距离后，再继续进行匹配。
//而该距离等于当前"部分匹配"结果的成中心对称的前后缀最大相同值。
//next数组就以此来构造。
int KMP(char text[], char pattern[], int next[], int tlen, int plen) {
    int i = 0, j = 0;
    while (i < tlen && j < plen) {
        if (j == -1 || text[i] == pattern[j]) {
            i++, j++;
        } else {
            j = next[j];
        }
    }
    return j == plen ? i - j : -1;
}

int main() {
    char txt[] = "abacbcdabacababaa", ptn[] = "ababaa";
    int next[strlen(ptn)];

    printf("Next Array is ");
    getNext(ptn, next, strlen(ptn));
    printArray(next, arrayLength(next));
    printf("Matched at %d ", KMP(txt, ptn, next, strlen(txt), strlen(ptn)));
    
    return 0;
}
