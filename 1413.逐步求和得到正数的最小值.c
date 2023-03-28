/*
 * @lc app=leetcode.cn id=1413 lang=c
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

int minStartValue(int* nums, int numsSize){
    int min = nums[0];
    for(int i=1;i<numsSize;i++){
        nums[i] = nums[i] + nums[i-1];
        if(nums[i] < min)min = nums[i];
    }
    return (1-nums[0])- (1-min) > 0?1 > 1-nums[0]?1:1-nums[0]:1>(1-min)?1:(1-min);
}
// @lc code=end

