/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] Ñî»ÔÈý½Ç
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>


int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **ans = (int**)malloc(sizeof(int*)*(numRows));
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int)*numRows);
    int *p = (int*)malloc(sizeof(int)*30);
    *p = 1;
    *ans = p;
    (*returnColumnSizes)[0] = 1;
    if(numRows == 1)return ans;
    p = (int*)malloc(sizeof(int) * 2);
    *p = 1;
    *(p+1) = 1;
    *(ans+1) = p;
    (*returnColumnSizes)[1] = 2;
    if(numRows == 2)return ans;
    
    for(int i=2;i<numRows;i++){
        p = (int*)malloc(sizeof(int)*(*returnSize));
        *p = 1;
        *(p+i) = 1;
        for(int j=1;j<i;j++){
            *(p+j) = *(*(ans+i-1)+j-1) + *(*(ans+i-1)+j);
        }
        (*returnColumnSizes)[i] = i+1;
        *(ans+i) = p;
    }
    return ans;
}
// @lc code=end

int main(){
    int **ans;
    int *returnSize = (int*)malloc(sizeof(int));
    int **returnColumnSizes = (int**)malloc(sizeof(int*));
    ans = generate(6, returnSize, returnColumnSizes);
    for(int i=0;i<6;i++){
        for(int j=0;j<=i;j++){
            printf("%d ", *(*(ans+i)+j));
        }
        printf("\n");
    }
    return 0;
}