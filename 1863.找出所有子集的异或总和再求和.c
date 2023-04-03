/*
 * @lc app=leetcode.cn id=1863 lang=c
 *
 * [1863] 找出所有子集的异或总和再求和
 */

// @lc code=start
// 使用选与不选的思路解决问题
#include <stdlib.h>
void dfs(int *nums, int n, int i, int *sum, int *val){
    if(i == n){
        *sum += *val;
        return;
    }
    dfs(nums, n, i+1, sum, val);
    (*val)^=nums[i];
    dfs(nums, n, i+1, sum, val);
}


int subsetXORSum(int* nums, int numsSize){
    int *sum = malloc(sizeof(int));
    int *val = malloc(sizeof(int));
    *sum = 0;
    *val = 0;
    dfs(nums, numsSize, 0, sum, val);
    return *sum;
}
// @lc code=end

