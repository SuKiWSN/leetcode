/*
 * @lc app=leetcode.cn id=1464 lang=c
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int maxProduct(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    return (nums[numsSize-1]-1) * (nums[numsSize-2]-1);
}
// @lc code=end

