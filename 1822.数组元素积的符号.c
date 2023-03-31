/*
 * @lc app=leetcode.cn id=1822 lang=c
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start


int arraySign(int* nums, int numsSize){
    int neg = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == 0)return 0;
        else if(nums[i] < 0)neg++;
    }
    return neg % 2?-1:1;
}
// @lc code=end

