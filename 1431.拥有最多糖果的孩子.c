/*
 * @lc app=leetcode.cn id=1431 lang=c
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    *returnSize = candiesSize;
    int max = 0;
    for(int i=0;i<candiesSize;i++){
        if(candies[i] > max) max = candies[i];
    }
    bool* res = malloc(sizeof(bool)* *returnSize);
    for(int i=0;i<*returnSize;i++){
        res[i] = max - candies[i] <= extraCandies ?true:false;
    }
    return res;
}
// @lc code=end

