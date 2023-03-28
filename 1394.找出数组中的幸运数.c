/*
 * @lc app=leetcode.cn id=1394 lang=c
 *
 * [1394] 找出数组中的幸运数
 */

// @lc code=start
#include <string.h>

int findLucky(int* arr, int arrSize){
    int nums[501];
    memset(nums, 0, sizeof(int)*(501));
    for(int i=0;i<arrSize;i++){
        nums[arr[i]]++;
    }
    for(int i=arrSize;i>0;i--){
        if(nums[i] == i)return i;
    }
    return -1;
}
// @lc code=end

