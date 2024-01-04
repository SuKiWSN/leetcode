/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int bisearch(int* nums, int s, int e, int target){
    int m;
    if(nums[e] == target)return e;
    else{
        while(s != (s+e)/2){
            m = (s+e)/2;
            if(nums[m] == target)return m;
            else if(nums[m] > target)e = m;
            else s = m;
        }
    }
    return s;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *res = (int*)malloc(sizeof(int)*2);
    res[0] = -1;
    res[1] = -1;
    if(numsSize == 0)return res;
    else if(nums[0] > target||nums[numsSize-1]<target)return res;
    int f = bisearch(nums, 0, numsSize-1, target);
    int s = -1, e = -1;
    *returnSize = 2;
    if(nums[f] == target){
        s = e = f;
        for(;s-1 >= 0 && nums[s-1] == target;s--);
        for(;e+1 < numsSize && nums[e+1] == target;e++);
    }
    res[0] = s;
    res[1] = e;
    return res;
}
// @lc code=end

