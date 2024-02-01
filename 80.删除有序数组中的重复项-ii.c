/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除有序数组中的重复项 II
 */
#include <stdio.h>
// @lc code=start
int removeDuplicates(int* nums, int numsSize) {
    int time = 1;
    for(int i=1;i<numsSize;i++){
        if(nums[i] == nums[i-1]){
            time++;
            if(time == 2){
                for(int j=i+1;j<numsSize && nums[j] == nums[i];j++)nums[j] = 1 << 16;
                time = 1;
            }
        }
    }
    int blank = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == 1<<16)blank++;
        else nums[i-blank] = nums[i];
    }
    return numsSize - blank;
}
// @lc code=end

