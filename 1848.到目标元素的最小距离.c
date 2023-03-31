/*
 * @lc app=leetcode.cn id=1848 lang=c
 *
 * [1848] 到目标元素的最小距离
 */

// @lc code=start
#include <stdlib.h>
int getMinDistance(int* nums, int numsSize, int target, int start){
    for(int i=0;i<numsSize;i++)if((start+i < numsSize && nums[start+i]==target) || (start-i >=0 && nums[start-i] == target))return i;
    return -1;
}
// @lc code=end

