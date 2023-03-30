/*
 * @lc app=leetcode.cn id=1752 lang=c
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool check(int* nums, int numsSize){
    if(numsSize == 1 || numsSize == 2)return true;
    int i=1;
    while(i<numsSize && nums[i] >= nums[i-1])i++;
    if(i == numsSize)return true;
    i++;
    // 如果原数组不是递增的话
    // 那它要是一个满足条件的数组那么它的第一个元素一定大于最后一个元素
    if(nums[0] < nums[numsSize-1])return false;
    while(i<numsSize && nums[i] >= nums[i-1])i++;
    if(i ==numsSize)return true;
    else return false;
}
// @lc code=end

