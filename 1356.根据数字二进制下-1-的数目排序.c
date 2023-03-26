/*
 * @lc app=leetcode.cn id=1356 lang=c
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int num1(int n){
    int res = 0;
    while(n){
        if(n%2 == 1)res++;
        n /= 2;
    }
    return res;
}

void fastsort(int* arr, int s, int e){
    int i = s, j = e;
    bool f = true;
    while(s < e){
        if(arr[s] > arr[e]){
            int t = arr[s];
            arr[s] = arr[e];
            arr[e] = t;
            f = !f;
        }
        if(f)s++;
        else e--;
    }
    if(i != s)fastsort(arr, i, s-1);
    if(j != s)fastsort(arr, s+1, j);
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    fastsort(arr, 0, arrSize-1);
    *returnSize = arrSize;
    int **a = malloc(sizeof(int*) * 2);
    *a = arr;
    int *b = malloc(sizeof(int) * arrSize);
    memset(b, 0, sizeof(int) * arrSize);
    *(a+1) = b;
    for(int i=0;i<arrSize;i++){
        a[1][i] = num1(a[0][i]);
    }
    for(int i=0;i<arrSize;i++){
        for(int j=0;j<arrSize-i-1;j++){
            if(a[1][j] > a[1][j+1]){
                int t = a[1][j];
                a[1][j] = a[1][j+1];
                a[1][j+1] = t;
                t = a[0][j];
                a[0][j] = a[0][j+1];
                a[0][j+1] = t;
            }
        }
    }
    return *a;
}
// @lc code=end

