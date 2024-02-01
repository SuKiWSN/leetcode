/*
 * @lc app=leetcode.cn id=74 lang=c
 *
 * [74] 搜索二维矩阵
 */
#include <stdbool.h>
#include <stdio.h>
// @lc code=start
bool bisearch(int* array, int* matrixColSize, int target){
    int s = 0, e = (*matrixColSize)-1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(array[mid] == target)return true;
        else if(array[mid] > target)e = mid-1;
        else s = mid+1;
    }
    return false;
}
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int s = 0, e = matrixSize-1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(matrix[mid][0] == target)return true;
        else if(matrix[mid][0] > target)e = mid-1;
        else s = mid+1;
    }
    if(s-1>=0 && matrix[s-1][(*matrixColSize)-1] >= target)return bisearch(matrix[s-1], matrixColSize, target);
    else if(s< matrixSize && matrix[s][0] <= target && matrix[s][(*matrixColSize)-1] > target)return bisearch(matrix[s], matrixColSize, target);
    else if(s+1 < matrixSize) return bisearch(matrix[s+1], matrixColSize, target);
    return false;
}
// @lc code=end

