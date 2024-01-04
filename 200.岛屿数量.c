/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void dfs(char** grid, int i, int j, int row, int col){
    grid[i][j] = '0';
    if(j+1 < col && grid[i][j+1] == '1')dfs(grid, i, j+1, row, col);
    if(i+1 < row && grid[i+1][j] == '1')dfs(grid, i+1, j, row, col);
    if(j-1 >= 0 && grid[i][j-1] == '1')dfs(grid, i, j-1, row, col);
    if(i-1 >= 0 && grid[i-1][j] == '1')dfs(grid, i-1, j, row, col);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int res = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            if(grid[i][j] == '1'){
                dfs(grid, i, j, gridSize, *gridColSize);
                res++;
            }
        }
    }
    return res;
}
// @lc code=end
