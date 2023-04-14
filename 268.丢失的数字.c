/*
 * @lc app=leetcode.cn id=268 lang=c
 *
 * [268] 丢失的数字
 */

// @lc code=start


int missingNumber(int* nums, int numsSize){
    int sum = (numsSize+1)*numsSize / 2;
    for(int i=0;i<numsSize;i++){
        sum -= nums[i];
    }
    return sum;
}
// @lc code=end

