/*
 * @lc app=leetcode.cn id=1460 lang=c
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), cmp);
    qsort(target, targetSize, sizeof(int), cmp);
    for(int i=0;i<arrSize;i++)if(arr[i] != target[i])return false;
    return true;
}
// @lc code=end

