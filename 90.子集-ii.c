/*
 * @lc app=leetcode.cn id=90 lang=c
 *
 * [90] 子集 II
 */
#include <stdio.h>
#include <stdlib.h>

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
void backtrack(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int k, int th, int idx, int** res){
    static int r0[10], visist [10]={0};
    if(th == k){
        int* r1 = malloc(sizeof(int) * k);
        for(int i = 0;i<k;i++)r1[i] = r0[i];
        res[*returnSize] = r1;
        returnColumnSizes[0][(*returnSize)++] = k;
        return;
    }
    if(idx == numsSize)return;
    r0[th] = nums[idx];
    visist[idx] = 1;
    if(!(idx-1 >= 0 && nums[idx-1] == nums[idx] && visist[idx-1] == 0))backtrack(nums, numsSize, returnSize, returnColumnSizes, k, th+1, idx+1, res);
    visist[idx] = 0;
    backtrack(nums, numsSize, returnSize, returnColumnSizes, k, th, idx+1, res);
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int)*10000);
    int** res = malloc(sizeof(int*)*10000);
    for(int i=0;i<=numsSize;i++){
        backtrack(nums, numsSize, returnSize, returnColumnSizes, i, 0, 0, res);
    }
    return res;
}
// @lc code=end
#define NUMSSIZE 5
int main(){
    int numsSize = NUMSSIZE;
    int array[NUMSSIZE] = {4, 4, 4, 1, 4};
    int* nums = malloc(sizeof(int) * numsSize);
    int* returnSize = malloc(sizeof(int));
    int** returnColumnSizes = malloc(sizeof(int*));
    for(int i=0;i<numsSize;i++)nums[i] = array[i];
    int** res = subsetsWithDup(nums, numsSize, returnSize, returnColumnSizes);
    for(int i=0;i<*returnSize;i++){
        for(int j=0;j<returnColumnSizes[0][i];j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}