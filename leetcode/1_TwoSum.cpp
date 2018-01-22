/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]
*/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int *pos = (int *)malloc(sizeof(int)*2);
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                pos[0] = i;
                pos[1] = j;
                break;
            }
        }
    }
    return pos;
}

int main() {
    int nums[] = {11, 7, 15, 2}, target = 9;
    int *pos = twoSum(nums, 4, 9);
    printf("indices: %d, %d\n", pos[0], pos[1]);
    return 0;
}
