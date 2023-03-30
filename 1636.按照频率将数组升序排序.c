/*
 * @lc app=leetcode.cn id=1636 lang=c
 *
 * [1636] 按照频率将数组升序排序
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
void fastsort(int *arr, int *arg, int s, int e){
    int i = s, j = e;
    bool f = true;
    while(s < e){
        if(arr[s] > arr[e]){
            int t = arr[s];
            arr[s] = arr[e];
            arr[e] = t;
            t = arg[s];
            arg[s] = arg[e];
            arg[e] = t;
        }
        if(f)s++;
        else e--;
    }
    if(i != s)fastsort(arr, arg, i, s-1);
    if(j != s)fastsort(arr, arg, s+1, j);
}
void fsort(int *arr, int s, int e){
    int i = s, j = e;
    bool f = true;
    while(s < e){
        if(arr[s] < arr[e]){
            int t = arr[s];
            arr[s] = arr[e];
            arr[e] = t;
        }
        if(f)s++;
        else e--;
    }
    if(i != s)fsort(arr, i, s-1);
    if(j != s)fsort(arr, s+1, j);
}

int* frequencySort(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *res = malloc(sizeof(int) * numsSize);
    int *record = malloc(sizeof(int) * 201);
    memset(record, 0, sizeof(int) * 201);
    int *arg = malloc(sizeof(int) * 201);
    for(int i=0;i<201;i++)arg[i] = i-100;
    for(int i=0;i<numsSize;i++){
        record[nums[i]+100]++;
    }
    fastsort(record, arg, 0, 200);
    int idx = 0;
    for(int i=0;i<201;i++){
        int s = i, e = i;
        while(e < 201 && record[e] == record[s])e++;
        e--;
        i = e;
        if(record[s] != 0 && s != e)fsort(arg, s, e);
    }
    for(int i=0;i<201;i++){
        for(int j=0;j<record[i];j++){
            res[idx++] = arg[i];
        }
    }
    return res;
}
// @lc code=end

int main(){
    int nums[4] = {1, 5, 0, 5};
    int numsSize = sizeof(nums) / sizeof(int);
    int *returnSize = malloc(sizeof(int));
    returnSize = frequencySort(nums, numsSize, returnSize);
    for(int i=0;i<numsSize;i++){
        printf("%d ", returnSize[i]);
    }
    printf("\n");
    return 0;
}