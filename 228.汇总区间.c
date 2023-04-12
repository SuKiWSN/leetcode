/*
 * @lc app=leetcode.cn id=228 lang=c
 *
 * [228] 汇总区间
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 学会使用sprintf
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    char **res = malloc(sizeof(char*)*(20));
    *returnSize = 0;
    for(int i=0;i<numsSize;i++){
        int j=i+1;
        while(j < numsSize && nums[j] == nums[j-1]+1)j++;
        res[*returnSize] = malloc(sizeof(char)*(40));
        memset(res[*returnSize], 0, 40);
        sprintf(res[*returnSize]+strlen(res[*returnSize]), "%d", nums[i]);
        if(i < j-1){
            sprintf(res[*returnSize]+strlen(res[*returnSize]), "->%d", nums[j-1]);
        }
        (*returnSize)++;
        i = j-1;

    }
    return res;
}
// @lc code=end

int main(){
    int nums[6] = {0,2,3,4,6,9};
    int *returnSize = malloc(sizeof(int));
    char **res = summaryRanges(nums, 6, returnSize);
    for(int i=0;i<*returnSize;i++){
        printf("%s\n", res[i]);
    }
    return 0;

}