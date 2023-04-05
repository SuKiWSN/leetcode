/*
 * @lc app=leetcode.cn id=1991 lang=c
 *
 * [1991] 找到数组的中间位置
 */

// @lc code=start


int findMiddleIndex(int* nums, int numsSize){
    int sum = 0, left = 0, right = 0;
    if(numsSize == 1)return 0;
    for(int i=0;i<numsSize;i++){
        sum += nums[i];
    }
    if(sum - nums[0] == 0)return 0;
    for(int i=1;i<numsSize;i++){
        left += nums[i-1];
        right = sum - left - nums[i];
        if(left == right)return i;
    }
    return -1;
}
// @lc code=end

