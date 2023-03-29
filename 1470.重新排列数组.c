/*
 * @lc app=leetcode.cn id=1470 lang=c
 *
 * [1470] 重新排列数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = numsSize;
    int *res = malloc(sizeof(int) * numsSize);
    int i = 0, tag = 0;
    while(tag < numsSize){
        res[tag++] = nums[i];
        res[tag++] = nums[i+n];
        i++;
    }
    return res;
}
// @lc code=end

