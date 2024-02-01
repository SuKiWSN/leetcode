/*
 * @lc app=leetcode.cn id=63 lang=c
 *
 * [63] 不同路径 II
 */

// @lc code=start
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int flag[100][100] = {0};
    for(int i=0;i<obstacleGridSize && obstacleGrid[i][0]!=1;i++)flag[i][0] = 1;
    for(int j=0;j<*obstacleGridColSize && obstacleGrid[0][j]!=1;j++)flag[0][j] = 1;
    for(int i=1;i<obstacleGridSize;i++){
        for(int j=1;j<*obstacleGridColSize;j++){
            if(obstacleGrid[i][j] == 1)flag[i][j] = 0;
            else flag[i][j] = flag[i-1][j] + flag[i][j-1];
        }
    }
    return flag[obstacleGridSize-1][(*obstacleGridColSize)-1];
}
// @lc code=end

