/*
 * @lc app=leetcode.cn id=2057 lang=c
 *
 * [2057] 值相等的最小索引
 */

// @lc code=start


int smallestEqual(int* nums, int numsSize){
    for(int i=0;i<numsSize;i++){
        if(i % 10 == nums[i])return i;
    }
    return -1;
}
// @lc code=end

