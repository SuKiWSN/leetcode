/*
 * @lc app=leetcode.cn id=1389 lang=c
 *
 * [1389] 按既定顺序创建目标数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    *returnSize = 0;
    int *res = malloc(sizeof(int) * numsSize);
    for(int i=0;i<indexSize;i++){
        if(index[i] < i){
            for(int j=0;j<i;j++){
                if(index[j] >= index[i])index[j]++;
            }
        }
    }
    for(int i=0;i<numsSize;i++){
        res[index[i]] = nums[i];
        (*returnSize)++;
    }
    return res;
}
// @lc code=end

