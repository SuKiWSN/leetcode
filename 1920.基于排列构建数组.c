/*
 * @lc app=leetcode.cn id=1920 lang=c
 *
 * [1920] 基于排列构建数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize){
    static int ans[1000];
    *returnSize = numsSize;
    for(int i=0;i<numsSize;i++){
        ans[i] = nums[nums[i]];
    }
    return ans;
}
// @lc code=end

