/*
 * @lc app=leetcode.cn id=1380 lang=c
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize = 0;
    int *res = malloc(sizeof(int)*matrixSize);
    for(int i=0;i<matrixSize;i++){
        int min = INT32_MAX, argmin;
        int j, k;
        for(j=0;j<*matrixColSize;j++){
            if(matrix[i][j] < min){
                min = matrix[i][j];
                argmin = j;
            }
        }
        int max = 0, argmax;
        for(k=0; k<matrixSize;k++){
            if(matrix[k][argmin] > max){
                max = matrix[k][argmin];
                argmax = k;
            }
        }
        if(argmax == i){
            res[(*returnSize)++] = matrix[argmax][argmin];
        }
    }
    return res;
}
// @lc code=end
int main(){
    int **matrix;
    matrix = malloc(sizeof(int *) * 2);
    for(int i=0;i<2;i++){
        *(matrix+i) = malloc(sizeof(int) * 2);
    }
    matrix[0][0] = 7;
    matrix[0][1] = 8;
    matrix[1][0] = 1;
    matrix[1][1] = 2;
    int matrixSize = 2;
    int *matrixColSize = malloc(sizeof(int));
    *matrixColSize = 2;
    int *returnSize = malloc(sizeof(int));
    int *res = luckyNumbers(matrix, matrixSize, matrixColSize, returnSize);
    for(int i=0;i<*returnSize;i++){
        printf("%d\n", res[i]);
    }
    return 0;
}