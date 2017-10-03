#include <stdio.h>
#define MAX_SIZE 7

typedef struct {
    int data[MAX_SIZE];
    int length;
}SqList;

int binarySearch(SqList &L, int key);

int main() {
    //SqList *L = (SqList *)malloc(sizeof(SqList));
    SqList L = {{1, 3, 5, 7, 8, 12, 25}, 7};
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
