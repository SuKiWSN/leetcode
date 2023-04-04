/*
 * @lc app=leetcode.cn id=1893 lang=c
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */

// @lc code=start
#include <stdbool.h>

bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right){
    int arr[51] = {0};
    for(int i=0;i<rangesSize;i++){
        for(int j=ranges[i][0]; j<=ranges[i][1]; j++){
            arr[j] = 1;
        }
    }
    for(int i=left; i<=right; i++){
        if(arr[i] == 0)return false;
    }
    return true;
}
// @lc code=end

