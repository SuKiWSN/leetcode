/*
 * @lc app=leetcode.cn id=59 lang=c
 *
 * [59] 螺旋矩阵 II
 */
#include <stdlib.h>
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int)*n);
    int** res = malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        returnColumnSizes[0][i] = n;
        *(res+i) = malloc(sizeof(int)*n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j] = 0;
        }
    }
    int direction = 0;
    int i, j;
    i = j = 0;
    res[0][0] = 1;
    for(int k=1;k<n*n;k++){
        if(direction==0){
            if(j+1<n && res[i][j+1]==0){
                res[i][++j] = k+1;

            }
            else{
                direction = 1;
                k--;
            }
        }
        else if(direction == 1){
            if(i+1<n && res[i+1][j]==0){
                res[++i][j] = k+1;
            }
            else{
                direction = 2;
                k--;
            }
        }
        else if(direction == 2){
            if(j-1>=0&&res[i][j-1]==0){
                res[i][--j] = k+1;
            }
            else{
                direction = 3;
                k--;
            }
        }
        else if(direction == 3){
            if(i-1>=0&&res[i-1][j]==0){
                res[--i][j] = k+1;
            }
            else{
                direction = 0;
                k--;
            }
        }
        
    }
    return res;
}
// @lc code=end

int main(){
    int n = 3;
    int* returnSize = malloc(sizeof(int));
    int** returnColumnSizes = malloc(sizeof(int*));
    int** res = generateMatrix(n, returnSize, returnColumnSizes);
    return 0;
}