/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
void trackback(int* nums, int numsSize, int* returnSize, int** res){
    static int th=0, res0[6], flag[6] = {0};
    if(th == numsSize){
        int* res1 = (int*)malloc(sizeof(int)*numsSize);
        for(int i=0;i<numsSize;i++)res1[i] = res0[i];
        res[(*returnSize)++] = res1;
        return;
    }
    for(int i=0;i<numsSize;i++){
        if(flag[i] == 0){
            flag[i] = 1;
            res0[th++] = nums[i];
            trackback(nums, numsSize, returnSize, res);
            th--;
            flag[i] =0;
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * 720);
    trackback(nums, numsSize, returnSize, res);
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<(*returnSize);i++){
        returnColumnSizes[0][i] = numsSize;
    }
    printf("%d\n", *returnSize);
    return res;
}
// @lc code=end

int main(){
    int* nums;
    int *returnSize = malloc(sizeof(int));
    int** returnColumnSizes = (int**)malloc(sizeof(int*));
    int numsSize = 3;
    nums = malloc(sizeof(int)*numsSize);
    int num[6] = {1, 2, 3};
    for(int i=0;i<numsSize;i++){
        nums[i] = num[i];
    }
    permute(nums, numsSize, returnSize, returnColumnSizes);
    return 0;
}