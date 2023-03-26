/*
 * @lc app=leetcode.cn id=1365 lang=c
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void fastsort(int *nums, short* arg, int s, int e){
    int i=s, j=e;
    bool f = true;
    while(s<e){
        if(nums[s] > nums[e]){
            int t = nums[s];
            nums[s] = nums[e];
            nums[e] = t;
            t = arg[s];
            arg[s] = arg[e];
            arg[e] = t;
            f = !f;
        }
        if(f)s++;
        else e--;
    }
    if(i!=s)fastsort(nums, arg, i, s-1);
    if(j!=s)fastsort(nums, arg, s+1, j);
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    // 快排➕记住原本的下标 
    // runtime beats 100 % of c submissions
    // memory usage beats 85.88 % of c submissions (6.5 MB)
    
    *returnSize = numsSize;
    short *arg = malloc(sizeof(short) * numsSize);
    for(int i=0;i<numsSize;i++)arg[i] = i;
    fastsort(nums, arg, 0, numsSize-1);
    int *res = malloc(sizeof(int) * numsSize);
    for(int i=0;i<numsSize;i++){
        if(i > 0 && nums[i] == nums[i-1])res[arg[i]] = res[arg[i-1]];
        else res[arg[i]] = i;
    }
    return res;
    // 暴力
    // *returnSize = numsSize;
    // int *res = malloc(sizeof(int)* numsSize);
    // for(int i=0;i<numsSize;i++)res[i] = numsSize-1;
    // for(int i=0;i<numsSize;i++){
    //     for(int j=i+1;j<numsSize;j++){
    //         if(nums[i] > nums[j]){
    //             res[j]--;
    //         }
    //         else if(nums[i] < nums[j]){
    //             res[i]--;
    //         }
    //         else{
    //             res[i]--;
    //             res[j]--;
    //         }
    //     }
    // }
    // return res;
}
// @lc code=end

