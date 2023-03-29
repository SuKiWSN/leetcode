/*
 * @lc app=leetcode.cn id=1572 lang=c
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start


int diagonalSum(int** mat, int matSize, int* matColSize){
    int res = 0;
    for(int i=0;i<matSize;i++){
        res += mat[i][i];
        res += mat[i][matSize-i-1];
    }
    if(matSize % 2)res -= mat[matSize / 2][matSize / 2];
    return res;
}
// @lc code=end

