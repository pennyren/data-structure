#include <stdio.h>
#include "utils.h"

int binarySearch(SqList &L, int key);

int main() {
    int test[] = {1, 3, 5, 7, 8, 12, 25};
    SqList L = initSqList(test, 7);
    int pos = binarySearch(L, 8);
    printf("The position of key is %d \n ", pos);
    return 0;
}

int binarySearch(SqList &L, int key) {
    int low = 0, high = L.length, mid;
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
