/*
 * @lc app=leetcode.cn id=1608 lang=c
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int specialArray(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int x = 0;
    int idx = 0;
    while(x <= nums[numsSize -1]){
        while(nums[idx] < x)idx++;
        int e = numsSize - idx;
        if ( e == x ) return x;
        else x++;
    }
    return -1;
}
// @lc code=end