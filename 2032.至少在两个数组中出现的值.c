/*
 * @lc app=leetcode.cn id=2032 lang=c
 *
 * [2032] 至少在两个数组中出现的值
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize){
    bool arr1[101] = {0};
    bool arr2[101] = {0};
    bool arr3[101] = {0};
    *returnSize = 0;
    for(int i=0;i<nums1Size;i++)arr1[nums1[i]] = true;
    for(int i=0;i<nums2Size;i++)arr2[nums2[i]] = true;
    for(int i=0;i<nums3Size;i++)arr3[nums3[i]] = true;
    int *res = malloc(sizeof(int)*(100));
    for(int i=0;i<101;i++){
        if(arr1[i]+arr2[i]+arr3[i] >= 2)res[(*returnSize)++] = i;
    }
    return res;
}
// @lc code=end

