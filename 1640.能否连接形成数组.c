/*
 * @lc app=leetcode.cn id=1640 lang=c
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int gethash(int *p, int size){
    int res = 0;
    for(int i=0;i<size;i++){
        res *= 13;
        res += p[i];
        res %= 1000007;
    }
    return res;
}

bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize){
    int idx = 0;
    for(int i=0;i<piecesSize;i++){
        int hashp = gethash(pieces[i], piecesColSize[i]);
        bool f = false;
        for(int j=0;j+piecesColSize[i]<=arrSize;j++){
            int hasharr = gethash(arr+j, piecesColSize[i]);
            if(hasharr == hashp){
                f = true;
                break;
            }
        }
        if(!f)return false;
    }
    return true;
}
// @lc code=end

