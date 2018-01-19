#include <stdio.h>
#include "utils.h"

//插入排序
void insertSort(int A[], int len);
void binaryInsertSort(int A[], int len);
void shellSort(int A[], int len);

//交换排序
void bubbleSort(int A[], int len);

int partition(int A[], int low, int high);
void quickSort(int A[], int low, int high); 

//选择排序
//都不稳定
void selectSort(int A[], int len);

void buildMaxHeap(int A[], int len);
void adjustDown(int A[], int k, int len);
void adjustUp(int A[], int k);
void heapSort(int A[], int len);

//归并排序
void merge(int A[], int low, int mid, int high);
void mergeSort(int A[], int low, int high);

//全局作用域
//test[0]可为哨兵位置
int test[] = {-1, 3, 8, 5, 12, 9, 7, 2, 16, 7};
int len = arrayLength(test);
//归并辅助数组
int *B = (int *)malloc(sizeof(int)*len);

int main() {
    //heapSort(test, arrayLength(test));
    printf("Sort: ");
    mergeSort(test, 0, len - 1);
    printArray(test, len);
    return 0;
}

//---------------------Insert Sort-------------------------//
void insertSort(int A[], int len) {
    int i, j;
    //A[0]哨兵，A[1]初始有序
    for (i = 2; i < len; i++) {
        if (A[i - 1] > A[i]) {
            A[0] = A[i];
            //寻找插入位置，边比较边移动
            for (j = i - 1; A[j] > A[0]; j--) {
                A[j + 1] = A[j];
            }
            //j + 1位置插入
            A[j + 1] = A[0];
        }
    }
}

//比较与移动分离，先折半查找待插入位置，再统一移动。
void binaryInsertSort(int A[], int len) {
    int i, j, low, high, mid;
    for (i = 2; i < len; i++) {
        A[0] = A[i];

        //折半查找
        low = 1; high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > A[0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        //移位
        for (j = i - 1; j >= high + 1; j--) {
            A[j + 1] = A[j];
        }

        //插入
        A[high + 1] = A[0];
    }
}

//缩小增量排序，将待排序表等间隔分割为子表，分别进行插入排序
//增量选取方式d1 = n/2，di+1 = di/2，最后增量为1
//不稳定排序
void shellSort(int A[], int len) {
    int i, j, dk, temp;
    //选取间隔
    for (dk = len / 2; dk >= 1; dk = dk/2) {
        //同一间隔不同分组，初始i为子表的第二个元素
        for(i = dk; i < len; i++) {
            //同一分组插入排序
            if(A[i] < A[i - dk]) {
                temp = A[i];
                //边查找边移位
                for (j = i - dk; j >= 0 && A[j] > temp; j -= dk) {
                    A[j + dk] = A[j];
                }
                //插入
                A[j + dk] = temp;
            }
        }
    }
}

//--------------------Swap Sort--------------------------//

//每一趟确定一个元素最终位置
void bubbleSort(int A[], int len) {
    int i, j, flag, temp;
    for (i = 0; i < len - 1; i++) {
        flag = false;
        //最小往左(上)冒
        for (j = len - 1; j > i; j--) {
            if (A[j - 1] > A[j]) {
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = true;
            }
        }

        //若已经有序，直接跳出循环
        if (flag == false) {
            return;
        }
    }
}

//快速排序，分治法思想，以子表第一个为基准
//小于基准值的交换的基准值左边，大于则在右边。
//一趟排序唯一确定一个元素最终位置
//递归的在子表中重复上述过程
//初始表有序或逆序，将会使快排的划分极不对称，效率最低。
//不稳定
void quickSort(int A[], int low, int high) {
    if(low < high) {
        //划分，返回已确定的一个元素最终位置
        int pos = partition(A, low, high);
        quickSort(A, low, pos - 1);
        quickSort(A, pos + 1, high);
    }
}

//划分方式，以当前表第一个元素作为枢轴值(基准值)对表进行划分
int partition(int A[], int low, int high) {
    int base = A[low];
    while (low < high) {
        //从后往前扫，将比基准值小的移到左端
        while (low < high && A[high] >= base) high--;
        A[low] = A[high]; //向左交换

        //从前往后扫，将比基准值大的移到右端
        while (low < high && A[low] <= base) low++;
        A[high] = A[low]; //向右交换
    }
    A[low] = base;
    return low;
}

//------------------Select Sort---------------------//
//不稳定
void selectSort(int A[], int len) {
    int i, j, min, temp;
    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (A[j] < A[min]) min = j;
        }
        if (min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

//堆排序，完全二叉树的顺序存储结构
//利用完全二叉树中双亲节点与孩子节点之间的关系
//在无序区选择最大(最小)元素
//不稳定

void buildMaxHeap(int A[], int len) {
    //i= len/2 ~ 1反复调整堆
    //i为完全二叉树最底层子树根节点
    for (int i = len/2; i > 0; i--) {
        adjustDown(A, i, len);
    }
}

//向下调整，k为向下调整节点
void adjustDown(int A[], int k, int len) {
    //子树根暂存
    A[0] = A[k];
    //以A[k]该根节点向下调整，以使其符合大根堆定义
    for (int i = 2*k; i <= len; i *= 2) {
        //取较大子节点下标
        if (i < len && A[i] < A[i + 1]) i++;

        //是否调整
        if(A[0] >= A[i]) {
            break;
        } else {
            //调整则继续向下筛选
            A[k] = A[i];
            //被调整节点
            k = i;
        }
    }
    A[k] = A[0];
}

void heapSort(int A[], int len) {
    int temp;
    //初始建堆
    buildMaxHeap(A, len);

    //n-1趟建堆
    for (int i = len; i > 1; i--) {
        //输出堆顶元素，且堆顶始终在A[1]处
        temp = A[1];
        A[1] = A[i];
        A[i] = temp;

        //再构建堆
        adjustDown(A, 1, i - 1);
    }
}

//堆删除根节点时，将堆中最后一个元素和堆顶交换，再对根节点向下调整重塑堆结构
//堆插入节点时，先将节点放在堆末端，再对新节点进行向上调整
//k为向上调节节点
void adjustUp(int A[], int k) {
    A[0] = A[k];
    int i = k/2; //双亲节点
    while (i > 0 && A[i] < A[0]) {
        A[k] = A[i];
        k = i;
        i = k/2;
    }
    A[k] = A[0];
}

//归并排序
//将前后两个相邻的有序表归并为一个有序表
//初始状态为单个元素就为一个有序表，然后依次合并再递归
//而两两合并的过程就是两个有序表合并为一个有序表的过程，即设置双指针即可
void merge(int A[], int low, int mid, int high) {
    //表示A的两段有序部分A[low...mid],A[mid+1...high]
    //将两段有序表复制到B中
    int i, j, k;
    for (k = low; k <= high; k++) B[k] = A[k];

    //合并
    i = low; j = mid + 1; k = low;
    while (i <= mid && j <= high) {
        if (B[i] <= B[j]) {
            A[k++] = B[i++];
        } else {
            A[k++] = B[j++];
        }
    }
    while (i <= mid) A[k++] = B[i++];
    while (j <= high) A[k++] = B[j++];
}

void mergeSort(int A[], int low, int high) {
    //递归栈的栈顶每个有序表为单个元素
    if (low < high) {
        int mid = (low + high) / 2;
        //左侧子序列递归排序
        mergeSort(A, low, mid);
        //右侧子序列递归排序
        mergeSort(A, mid + 1, high);
        //归并
        merge(A, low, mid, high);
    }
}
