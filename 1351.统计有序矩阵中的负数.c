/*
 * @lc app=leetcode.cn id=1351 lang=c
 *
 * [1351] 统计有序矩阵中的负数
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countNegatives(int** grid, int gridSize, int* gridColSize){
    grid[gridSize-1][*gridColSize-1] = grid[gridSize-1][*gridColSize-1]<0?1:0;
    for(int i=gridSize-1; i>=0; i--){
        for(int j=*gridColSize-1;j>=0;j--){
            if(i == gridSize-1 && j == *gridColSize-1)continue;
            if(grid[i][j] < 0)grid[gridSize-1][*gridColSize-1]++;
            else break;
        }
    }
    return grid[gridSize-1][(*gridColSize)-1];
}
// @lc code=end

int main(){
    int gridSize=4;
    int grid[4][4] = {{4,3,2,-1}, {3,2,1,-1}, {1,1,-1,-2}, {-1,-1,-2,-3}};
    int (*g)[4] = grid;
    int* gridColSize = (int*)malloc(sizeof(int));
    *gridColSize = 4;
    // for(int i=0;i<*gridColSize;i++)*(grid+i) = (int*)malloc(sizeof(int) * *gridColSize);
    // for(int i=0;i<gridSize;i++){
    //     for(int j=0;j<*gridColSize;j++){
    //         scanf("%d", &grid[i][j]);
    //     }
    // }
    int res = countNegatives(g, gridSize, gridColSize);
    printf("%d\n", res);
}
