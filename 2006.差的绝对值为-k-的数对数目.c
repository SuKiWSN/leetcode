/*
 * @lc app=leetcode.cn id=2006 lang=c
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

// @lc code=start
#include <stdlib.h>

int countKDifference(int* nums, int numsSize, int k){
    int res = 0;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(abs(nums[i]-nums[j]) == k)res++;
        }
    }
    return res;
}
// @lc code=end