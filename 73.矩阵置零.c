/*
 * @lc app=leetcode.cn id=73 lang=c
 *
 * [73] 矩阵置零
 */

// @lc code=start
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int fr = 1, fc = 1;
    for(int i=0;i<*matrixColSize;i++){
        if(matrix[0][i] == 0){
            fr = 0;
            break;
        }
    }
    for(int j=0;j<matrixSize;j++){
        if(matrix[j][0] == 0){
            fc = 0;
            break;
        }
    }
    for(int i=1;i<*matrixColSize;i++){
        for(int j=0;j<matrixSize;j++){
            if(matrix[j][i] == 0){
                matrix[0][i] = 0;
                break;
            }
        }
    }
    for(int i=1;i<matrixSize;i++){
        for(int j=0;j<*matrixColSize;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                break;
            }
        }
    }
    for(int j=1;j<*matrixColSize;j++){
        if(matrix[0][j] == 0){
            for(int i=0;i<matrixSize;i++)matrix[i][j] = 0;
        }
    }
    for(int i=1;i<matrixSize;i++){
        if(matrix[i][0] == 0){
            for(int j=0;j<*matrixColSize;j++)matrix[i][j] = 0;
        }
    }
    if(fr == 0){
        for(int j=0;j<*matrixColSize;j++)matrix[0][j] = 0;
    }
    if(fc == 0){
        for(int i=0;i<matrixSize;i++)matrix[i][0] = 0;
    }
}
// @lc code=end

