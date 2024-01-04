/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = matrixSize * *matrixColSize;
    int k = *returnSize;
    int* res = malloc(sizeof(int)*100);
    int turn = 0;
    int i, j;
    i = j = 0;
    while(k--){
        res[*returnSize-k-1] = matrix[i][j];
        matrix[i][j] = 101;
        if(turn == 0){
            if(j+1<*matrixColSize && matrix[i][j+1] != 101)j++;
            else{
                i++;
                turn = 1;
            }
        }
        else if(turn == 1){
            if(i+1<matrixSize && matrix[i+1][j] != 101)i++;
            else{
                j--;
                turn = 2;
            }
        }
        else if(turn == 2){
            if(j-1>=0 && matrix[i][j-1] != 101)j--;
            else{
                i--;
                turn = 3;
            }
        }
        else if(turn == 3){
            if(i-1>=0 && matrix[i-1][j] != 101)i--;
            else{
                j++;
                turn = 0;
            }
        }
    }
    return res;
}
// @lc code=end

