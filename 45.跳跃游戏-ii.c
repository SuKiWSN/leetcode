/*
 * @lc app=leetcode.cn id=45 lang=c
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
// 贪心算法
#include <stdlib.h>
#include <stdio.h>

int min(int a, int b){
    return a < b ? a : b;
}

int jump(int* nums, int numsSize) {
    int minium[numsSize];
    for(int i=0;i<numsSize;i++)minium[i] =  __INT_MAX__;
    minium[0] = 0;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<=i+nums[i];j++){
            if(j < numsSize)minium[j] = min(minium[i]+1, minium[j]);
        }
    }
    return minium[numsSize-1];
}
// @lc code=end

