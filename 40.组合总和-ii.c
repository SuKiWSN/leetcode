/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
 */
#include <string.h>
#include <stdlib.h>
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void trackback(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int** res, int idx){
    static int res0[100];
    static int k = 0;
    if(idx == candidatesSize || target < 0)return;
    if(target == 0){
        returnColumnSizes[0][*returnSize] = k;
        int *res1 = (int*)malloc(sizeof(int)*100);
        for(int i=0;i<k;i++)res1[i] = res0[i];
        res[(*returnSize)++] = res1;
        return;
    }
    trackback(candidates, candidatesSize, target, returnSize, returnColumnSizes, res, idx+1);
    res0[k++] = candidates[idx];
    trackback(candidates, candidatesSize, target-candidates[idx], returnSize, returnColumnSizes, res, idx+1);
    k--;
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** res;
    res = (int**)malloc(sizeof(int*)*150);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int)*150);
    memset(*returnColumnSizes, 0, sizeof(returnColumnSizes));
    trackback(candidates, candidatesSize, target, returnSize, returnColumnSizes, res, 0);
    return res;
}
// @lc code=end

