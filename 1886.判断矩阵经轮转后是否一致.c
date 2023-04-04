/*
 * @lc app=leetcode.cn id=1886 lang=c
 *
 * [1886] 判断矩阵经轮转后是否一致
 */

// @lc code=start
#include <stdbool.h>
// 旋转90 度 y, n-x
// 旋转180度 n-x, n-y
// 旋转270度 n-y, x

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize){
    bool f0 = true, f1 = true, f2 = true, f3 = true;
    for(int i=0;i<matSize;i++){
        for(int j=0;j<*matColSize;j++){
            if(mat[i][j] != target[i][j])f0 = false;
            if(mat[j][matSize-1-i] != target[i][j])f1=false;
            if(mat[matSize-1-i][matSize-1-j] != target[i][j])f2 = false;
            if(mat[matSize-1-j][i] != target[i][j])f3=false;
            if(!(f0||f1||f2||f3))return false;
        }
    }
    return true;
}
// @lc code=end

