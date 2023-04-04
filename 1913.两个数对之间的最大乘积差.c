/*
 * @lc app=leetcode.cn id=1913 lang=c
 *
 * [1913] 两个数对之间的最大乘积差
 */

// @lc code=start
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int maxProductDifference(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize-2]*nums[numsSize-1] - nums[0] * nums[1];
}
// @lc code=end

