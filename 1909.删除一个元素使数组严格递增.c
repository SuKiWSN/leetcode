/*
 * @lc app=leetcode.cn id=1909 lang=c
 *
 * [1909] 删除一个元素使数组严格递增
 */

// @lc code=start
#include <stdbool.h>

bool canBeIncreasing(int* nums, int numsSize){
    bool f = true;
    for(int i=0;i<numsSize-1;i++){
        if(nums[i] >= nums[i+1]){
            if(f == false)return false;
            else{
                // 删左边的数,边界i=0额外判断
                if((i > 0 && nums[i-1] < nums[i+1])||(i == 0))f = false;
                // 删右边的数,边界i=numsSize-2额外判断
                else if((i < numsSize-2 && nums[i] < nums[i+2])||(i == numsSize-2)){
                    f = false;
                    i++;
                }
                // 两种删法都不行
                else return false;
            }
        }
    }
    return true;
}
// @lc code=end

