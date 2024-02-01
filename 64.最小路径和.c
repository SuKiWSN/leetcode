/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 */

// @lc code=start
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int flag[200][200] = {0};
    flag[0][0] = grid[0][0];
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            if(i == 0 && j == 0)continue;
            if(i == 0){
                flag[i][j] = flag[i][j-1] + grid[i][j];
            }
            else if(j==0){
                flag[i][j] = flag[i-1][j] + grid[i][j];
            }
            else if(i != 0 && j != 0){
                 flag[i][j] = flag[i][j-1] < flag[i-1][j] ? flag[i][j-1]+grid[i][j] : flag[i-1][j]+grid[i][j];
            }
        }
    }
    return flag[gridSize-1][(*gridColSize)-1];
}
// @lc code=end

