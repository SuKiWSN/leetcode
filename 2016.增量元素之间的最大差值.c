/*
 * @lc app=leetcode.cn id=2016 lang=c
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
// 一次循环记录每个位置前缀最小值
#include <stdbool.h>

int maximumDifference(int* nums, int numsSize){
    int max = -1, min =nums[0];
    for(int i=1;i<numsSize;i++){
        max = (nums[i]-min > max)&&nums[i] != min ? nums[i]-min : max;
        if(nums[i] < min)min = nums[i];
    }
    return max;
}
// @lc code=end

