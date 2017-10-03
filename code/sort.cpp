#include <stdio.h>

void insertSort(int arr[], int len) {
    int i, j;
    for (i = 2; i <= len; i++) {
        if (arr[i] < arr[i - 1]) {
            arr[0] = arr[i];
            for (j = i - 1; arr[0] < arr[j]; j--) { //ֻ����ֵ��arr[0]���Ĳ��ƶ�
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = arr[0];
        }
    }
}

int main() {
    int array[] = {0,2,1,7,4,12,3,9};
    int i = 1;
    insertSort(array, 7);
    while(i<= 7) {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
    return 0;
}
