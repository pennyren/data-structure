#include <stdio.h>
#include "utils.h"

typedef struct {
    int data;
    int first;
}IndexList;

int binarySearch(SqList &L, int key);
int seqSearch(SeqList &L, int key);
int blockSearch(int block[], IndexList L[], int blockLength, int indexLength, int key);

int main() {
    int test[] = {1, 3, 5, 6, 7, 8, 10, 12, 15, 17};
    IndexList B[] = {{5, 0}, {10, 3}, {17, 7}};
    SqList L = initSqList(test, arrayLength(test));
    printf("Binary Search pos is %d\n ", binarySearch(L, 7));
    printf("Block Search pos is %d\n ", blockSearch(test, B, arrayLength(test), arrayLength(B), 7));
    return 0;
}

//注意其查找过程中的判定树，高度和完全二叉树一致
//失败节点等于n+1
int binarySearch(SqList &L, int key) {
    int low = 0, high = L.length - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == key) {
            return mid;
        } else if (L.data[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

//data[0]设置为哨兵，以减少不必要的语句判断
//从后往前查找
int seqSearch(SeqList &L, int key) {
    int i;
    L.data[0] = key;
    for (i = L.length; L.data[i] != key; i--);
    return i;
}

//索引表有序，索引表中每个元素含有各块的最大关键字和各块第一个元素的地址
//第一块的最大关键字小于第二个块中所有记录的关键字。
//当每块元素个数为根号n时，ASL最小。
int blockSearch(int block[], IndexList L[], int blockLength, int indexLength, int key) {
    int start, last, i;
    if (key > L[indexLength - 1].data) return -1;
    
    //索引表查找
    for (i = 0; i < indexLength; i++) {
        if (key <= L[i].data) {
            break;
        }
    }

    start = L[i].first;
    last = (i == indexLength - 1) ? blockLength : L[i + 1].first;

    //块内查找
    while (--last >= start) {
        if (block[last] == key) {
            return last;
        }
    }
    return -1;
}
