/*
 * @lc app=leetcode.cn id=1337 lang=c
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int sumi(int* row, int* matColSize){
    int res = 0;
    for(int i=0;i<*matColSize;i++){
        res += row[i];
    }
    return res;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int arr[2][matSize];
    *returnSize = k;
    for(int i=0;i<matSize;i++){
        arr[0][i] = sumi(mat[i], matColSize);
        arr[1][i] = 1;
    }
    int *res = malloc(sizeof(int)*k);
    for(int i=0;i<k;i++){
        int min = 100, argmin = 0;
        for(int j=0;j<matSize;j++){
            if(arr[0][j] < min && arr[1][j]){
                min = arr[0][j];
                argmin = j;
            }
        }
        arr[1][argmin] = 0;
        res[i] = argmin;
    }
    return res;
}
// @lc code=end

