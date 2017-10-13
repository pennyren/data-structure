#include <stdio.h>
#include "utils.h"

void insertSort(int arr[], int len) {
    int i, j;
    for (i = 2; i <= len; i++) {
        if (arr[i] < arr[i - 1]) {
            arr[0] = arr[i];
            for (j = i - 1; arr[0] < arr[j]; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = arr[0];
        }
    }
}

int main() {
    int test[] = {6, 2, 1, 7, 4, 12, 3, 9};
    insertSort(test, arrayLength(test));
    printArray(test, arrayLength(test));
    return 0;
}
