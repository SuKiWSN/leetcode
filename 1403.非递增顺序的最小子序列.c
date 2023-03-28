/*
 * @lc app=leetcode.cn id=1403 lang=c
 *
 * [1403] 非递增顺序的最小子序列
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b){
    // return *(int*)a - *(int*)b; 升序
    return *(int*)b - *(int*)a;//降序
}
int* minSubsequence(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int sum = 0;
    int t = 0;
    for(int i=0;i<numsSize;i++)sum += nums[i];
    for(int i=0;i<numsSize;i++){
        if(t > sum - t)return nums;
        else{
            t += nums[i];
            (*returnSize)++;
        }
    }
    return nums;
}
// @lc code=end

int main(){
    int nums[5] = {4, 3, 10, 9, 8};
    int *returnSize = malloc(sizeof(int));
    int *res = minSubsequence(nums, sizeof(nums)/sizeof(int), returnSize);
    for(int i=0;i<*returnSize;i++){
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
