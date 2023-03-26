/*
 * @lc app=leetcode.cn id=1317 lang=c
 *
 * [1317] 将整数转换为两个无零整数的和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool haszero(int n){
    while(n){
        if(n % 10 == 0)return true;
        n /= 10;
    }
    return false;
}

int* getNoZeroIntegers(int n, int* returnSize){
    *returnSize = 2;
    int *res = malloc(sizeof(int)*2);
    for(int i=1;i<n;i++){
        if(haszero(i) || haszero(n-i))continue;
        else {
            *res = i;
            *(res+1) = n-i;
        }
    }
    return res;
}
// @lc code=end

