/*
 * @lc app=leetcode.cn id=48 lang=c
 *
 * [48] 旋转图像
 */

// @lc code=start
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int matrix2[20][20];
    for(int i=0;i<matrixSize;i++)
        for(int j=0;j<matrixSize;j++)
            matrix2[i][j] = matrix[i][j];
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixSize;j++){
            matrix[j][matrixSize-i-1] = matrix2[i][j];
        }
    }
}
// @lc code=end

