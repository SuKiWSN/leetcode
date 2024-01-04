/*
 * @lc app=leetcode.cn id=55 lang=c
 *
 * [55] 跳跃游戏
 */
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
// @lc code=start
bool canJump(int* nums, int numsSize) {
    int k = 0;
    for(int i=0;i<numsSize;i++){
        if(i > k)return false;
        k = k>nums[i]+i?k:nums[i]+i;
    }
    return true;
    // bool f[numsSize];
    // memset(f, 0, sizeof(f));
    // f[0] = true;
    // for(int i=0;i<numsSize-1;i++){
    //     if(f[i] == false)continue;
    //     for(int j=i+1;j<=i+nums[i]&&j<numsSize;j++){
    //         f[j] = true;
    //     }
    // }
    // return f[numsSize-1];
}
// @lc code=end

int main(){
    int numsSize = 5;
    int* nums = malloc(sizeof(int)*numsSize);
    int num[5] = {3,2,1,0,4};
    for(int i=0;i<numsSize;i++)nums[i] = num[i];
    bool res = canJump(nums, numsSize);
    printf("%d\n", res);
    return 0;
}