/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size + nums2Size, mid = len / 2;
    double *combine = (double *)malloc(sizeof(double) * len);
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            combine[k++] = nums1[i++];
        } else {
            combine[k++] = nums2[j++];
        }
    }
    while(i < nums1Size) {
        combine[k++] = nums1[i++];
    }
    while(j < nums2Size) {
        combine[k++] = nums2[j++];
    }
    return len % 2 == 0 ? (combine[mid] + combine[mid - 1]) / 2 : combine[mid];
}

int main() {
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    //%m.nf, %md
    printf("%.1f", findMedianSortedArrays(nums1, 2, nums2, 2));
    return 0;
}