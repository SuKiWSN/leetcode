/*
 * @lc app=leetcode.cn id=1437 lang=c
 *
 * [1437] 是否所有 1 都至少相隔 k 个元素
 */

// @lc code=start

#include <stdio.h>
#include <stdbool.h>

bool kLengthApart(int* nums, int numsSize, int k){
    int i = 0;
    while(i < numsSize && nums[i] != 1)i++;
    i++;
    while(i < numsSize){
        for(int j =0;j<k;j++){
            if(nums[i] == 1)return false;
            i++;
            if(i >= numsSize)break;
        }
        while(i < numsSize && nums[i] == 0)i++;
        i++;
    }
    return true;
}
// @lc code=end

