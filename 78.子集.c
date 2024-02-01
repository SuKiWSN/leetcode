/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 */
#include <stdlib.h>
#include <stdio.h>
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* nums, int numsSize, int k, int* returnSize, int** ans, int th, int idx){
    if(idx > numsSize)return;
    static int r1[10] = {0};
    if(th == k){
        int* r2 = malloc(sizeof(int)*k);
        for(int i=0;i<k;i++)r2[i] = r1[i];
        ans[(*returnSize)++] = r2;
        return;
    }
    r1[th] = nums[idx];
    if(th+numsSize-idx >= k)backtrack(nums, numsSize, k, returnSize, ans, th+1, idx+1);
    if(th+numsSize-idx-1 >=k)backtrack(nums, numsSize, k, returnSize, ans, th, idx+1);
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** ans = malloc(sizeof(int*)*5000);
    *returnColumnSizes = malloc(sizeof(int)*5000);
    for(int i=0;i<=numsSize;i++){
        int t = *returnSize;
        backtrack(nums, numsSize, i, returnSize, ans, 0, 0);
        for(int j=t;j<*returnSize;j++)returnColumnSizes[0][j] = i;
    }
    return ans;
}
// @lc code=end

