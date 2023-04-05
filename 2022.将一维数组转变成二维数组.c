/*
 * @lc app=leetcode.cn id=2022 lang=c
 *
 * [2022] 将一维数组转变成二维数组
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes){
    int **res;
    if(originalSize != m*n){
        *returnSize = 0;
        return res;
    }
    res = malloc(sizeof(int *)*m);
    *returnSize = m;
    *returnColumnSizes = malloc(sizeof(int)*m);
    for(int i=0;i<m;i++){
        res[i] = malloc(sizeof(int)*n);
        returnColumnSizes[0][i] = n;
        for(int j=0;j<n;j++){
            res[i][j] = original[i*n+j];
        }
    }
    return res;
}
// @lc code=end

