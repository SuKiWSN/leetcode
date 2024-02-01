/*
 * @lc app=leetcode.cn id=81 lang=c
 *
 * [81] 搜索旋转排序数组 II
 */
#include <stdio.h>
#include <stdbool.h>
// @lc code=start

bool bisearch(int* nums, int numsSize, int target, int s, int e){
    while(s <= e){
        int mid = s + (e-s)/2;
        if(nums[mid] > target)e = mid-1;
        else if(nums[mid] < target)s = mid+1;
        else return true;
    }
    return false;
}
bool search(int* nums, int numsSize, int target) {
    int k = 0;
    for(int i=1;i<numsSize;i++){
        if(nums[i] < nums[i-1]){
            k = i;
            break;
        }
    }
    bool b1 = bisearch(nums, numsSize, target, 0, k-1);
    bool b2 = bisearch(nums, numsSize, target, k, numsSize-1);
    return b1 || b2;
}
// @lc code=end

