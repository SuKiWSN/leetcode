/*
 * @lc app=leetcode.cn id=1929 lang=c
 *
 * [1929] 数组串联
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    *returnSize = 2 * numsSize;
    int *res = malloc(sizeof(int)*(numsSize*2));
    for(int i=0;i<numsSize;i++){
        res[i] = nums[i];
        res[i+numsSize] = nums[i];
    }
    return res;
}
// @lc code=end

