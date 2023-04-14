/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 */

// @lc code=start


void moveZeroes(int* nums, int numsSize){
    int idx = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] != 0)nums[idx++] = nums[i];
    }
    for(int i=idx;i<numsSize;i++)nums[i] = 0;
}
// @lc code=end

