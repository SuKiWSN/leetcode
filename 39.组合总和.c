/*
 * @lc app=leetcode.cn id=39 lang=c
 *
 * [39] 组合总和
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void trackback(int* candidates, int candidatesSize, int target, int idx, int* returnSize, int** returnColumnSizes, int** res){
    static int res0[100];
    static int k = 0;
    if(target <0 || idx == candidatesSize)return;
    if(target == 0){
        (*returnColumnSizes)[*returnSize] = k;
        int* res1 = (int*)malloc(sizeof(int)*100);
        for(int i=0;i<(*returnColumnSizes)[*returnSize];i++){
            res1[i] = res0[i];
        }
        res[(*returnSize)++] = res1;
        return;
    }
    // 不选第idx个
    trackback(candidates, candidatesSize, target, idx+1, returnSize, returnColumnSizes, res);
    // 选第idx个
    res0[k++] = candidates[idx];
    trackback(candidates, candidatesSize, target-candidates[idx], idx, returnSize, returnColumnSizes, res);
    k--;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*)*150);
    *returnColumnSizes = (int*)malloc(sizeof(int)*150);
    memset(*returnColumnSizes, 0, sizeof(returnColumnSizes));
    *returnSize = 0;
    trackback(candidates, candidatesSize, target, 0, returnSize, returnColumnSizes, res);
    return res;
}
// @lc code=end

int main(){
    int* candidates;
    candidates = (int*)malloc(sizeof(int)*100);
    candidates[0] = 2;
    candidates[1] = 3;
    candidates[2] = 6;
    candidates[3] = 7;
    int candidatesSize = 4;
    int target = 7;
    int* returnSize;
    returnSize = (int*)malloc(sizeof(int));
    int** returnColumnSizes;
    returnColumnSizes = (int**)malloc(sizeof(int*));
    int** res;
    res = combinationSum(candidates, candidatesSize, target, returnSize, returnColumnSizes);
    for(int i=0; i<*returnSize;i++){
        for(int j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}