/*
 * @lc app=leetcode.cn id=219 lang=c
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <stdbool.h>
#include <stdlib.h>
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i] == nums[j] && j-i <= k)return true;
        }
    }
    return false;
}
// @lc code=end

