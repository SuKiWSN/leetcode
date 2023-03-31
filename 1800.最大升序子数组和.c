/*
 * @lc app=leetcode.cn id=1800 lang=c
 *
 * [1800] 最大升序子数组和
 */

// @lc code=start


int maxAscendingSum(int* nums, int numsSize){
    int max = nums[0], t = nums[0];
    for(int i=1;i<numsSize;i++){
        if(nums[i] > nums[i-1]){
            t += nums[i];
            if(t > max)max = t;
        }
        else{
            t = nums[i];
        }
    }
    return max;
}
// @lc code=end

