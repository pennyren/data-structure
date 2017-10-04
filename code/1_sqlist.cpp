#include <stdio.h>
#include "utils.h"

void del(SqList &L, int e);
void reverse(SqList &L);
void orderedUnique(SqList &L);

void partialReverse(int A[], int from, int to);
void cycleMove(int A[], int n, int p);

int *mergeSqList(int A[], int B[], int m, int n);
int majority(int A[], int n);

int main() {
	int test[] = {2, 3, 4, 2, 2, 2, 4, 2, 5};
	SqList L = initSqList(test, arrayLength(test));

	printf("Origin: ");
    printArray(L.data, L.length);
    printf("Majority: %d\n", majority(L.data, L.length));

    printf("Delete 2: ");
    del(L, 2);
    printArray(L.data, L.length);

    printf("Reverse: ");
    reverse(L);
    printArray(L.data, L.length);

    printf("OrderedUnique: ");
    orderedUnique(L);
    printArray(L.data, L.length);

    return 0;
}


//删除顺序表值为x元素[6,3,5,7,5,8,11,9,5] => [6,3,5,7,8,11,9]
void del(SqList &L, int e) {
	int k = 0; //重新计数，记录值不等于e的元素个数，即新数组元素位置
	for(int i = 0; i < L.length; i++) {
		if (L.data[i] != e) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}


//元素逆置[1,2,3,4,5] => [5,4,3,2,1]
void reverse(SqList &L) {
	int temp;
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length -i - 1] = temp;
	}
}


//有序顺序表删除重复元素[1,2,2,3,4,4,4,5] => [1,2,3,4,5]
void orderedUnique(SqList &L) {
	//类似插入排序，以第一个为基准认为不重复
	int i, j;
	for (i = 0, j = 1; j < L.length; j++) {
		if (L.data[i] != L.data[j]) {
			L.data[++i] = L.data[j];
		}
	}
	L.length = i + 1;
}

//将数组循环左移P位，循环的元素就相当于正常序列的分段三次逆置。
//[6,3,5,7,9,11] 左移3 => [7,9,11,6,3,5]
void partialReverse(int A[], int from, int to) {
	int length, temp;
	length = to - from + 1;
	for (int i = 0; i < length / 2; i++) {
		temp = A[from + i];
		A[from + i] = A[to - i];
		A[to - i] = temp;
	}
}
void cycleMove(int A[], int n, int p) {
	partialReverse(A, 0, p - 1);
	partialReverse(A, p, n - 1);
	partialReverse(A, 0, n - 1);
}

//两有序数组合并为一个有序 O(m + n);
int *mergeSqList(int A[], int B[], int m, int n) {
	int length = m + n;
	int *C = (int *)malloc(sizeof(int)*length);
	int i = 0, j = 0, k = 0;
	while ((i < m) && (j < n)) {
		if(A[i] < B[j]) {
			C[k++] = A[i++];
		} else {
			C[k++] = B[j++];
		}
	}
	while (i < m) {
		C[k++] = A[i++];
	}
	while (j < n) {
		C[k++] = B[j++];
	}
	return C;
}

//找出主元素，且主元素个数大于n/2
//依次向后扫描，将第一个遇到的数Num保存到c中，并记录出现的次数为1
//若遇到下一个整数仍为Num，计数加一，否则减一，当计数减为0时，将遇到的下一整数
//保存c中，计数重新为1，重复上述，知道扫描完数组。
int majority(int A[], int n) {
    int num = A[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] == num) {
            count++;
        } else if (count > 0) {
            count--;
        } else {
            num = A[i];
            count = 1;
        }
    }
    //统计候选元素实际出现次数
    if (count > 0) {
        for (int i = count = 0; i < n; i++) {
            (A[i] == num) && count++;
        }
    }
    return (count > n/2) ? num : -1;
}


//时间复杂度O(n^2)
int _majority(int A[], int n) {
	int el, c = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i] == A[j]) count++;
		}
		if (count > c) {
			el = A[i];
			c = count;
		}
		count = 0;
	}
    return (c > n / 2) ? el : -1;
}
