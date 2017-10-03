#include <stdio.h>
#include <stdlib.h>
#define arrLength(a) (sizeof(a) / sizeof(*a))
#define maxSize 100

//静态分配
typedef struct {
	int data[maxSize];
	int length;
}SqList;

//动态分配
typedef struct {
	int *data;
	int length;
}SeqList;

void print(SqList &L) {
	int *a = L.data;
	int i = L.length;
	for (int j = 0; j < i; j++) {
		if (j == 0) {
			printf("[%d, ", a[j]);
		} else if (j == i-1) {
			printf("%d]\n", a[j]);
		} else {
			printf("%d, ", a[j]);
		}
	}
}

void printArrary(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			printf("[%d, ", a[i]);
		} else if (i == n-1) {
			printf("%d]\n", a[i]);
		} else {
			printf("%d, ", a[i]);
		}
	}
}

void copyArray(SqList &L, int *a) {
	for (int i = 0; i < L.length; i++) {
		L.data[i] = a[i];
	}
}

void reverse(SqList &L);
void delElement(SqList &L, int e);
void delSame(SqList &L);
void partialReverse(int A[], int from, int to);
void cycleMove(int A[], int n, int p);
int *mergeSqList(int A[], int B[], int m, int n);
int majority(int A[], int n);

int main() {
	int foo[]= {2, 4, 6, 8};
	int data[] = {1, 3, 5, 7, 9, 11, 13, 15};
	int majorityData[] = {0, 3, 5, 3, 7, 3, 3, 3};
	SqList L, Lc;
	L.length = 8;
	Lc.length = 12;
	
	int el = majority(majorityData, 8);
	printf("majority=%d\n", el );

	return 0;
}

//顺序表元素逆置
//[1,2,3,4,5] => [5,4,3,2,1]
void reverse(SqList &L) {
	int temp;
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length -i - 1] = temp;
	}
}

//删除顺序表值为x的元素
//[6,3,5,7,5,8,11,9,5] => [6,3,5,7,8,11,9]
void delElement(SqList &L, int e) {
	int k = 0; //重新计数，记录值不等于e的元素个数，即新数组元素位置
	for(int i = 0; i < L.length; i++) {
		if (L.data[i] != e) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}

//有序顺序表删除重复元素
//[1,2,2,3,4,4,4,5] => [1,2,3,4,5]
void delSame(SqList &L) {
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
int majority(int A[], int n) {
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
