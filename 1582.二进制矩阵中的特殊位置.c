/*
 * @lc app=leetcode.cn id=1582 lang=c
 *
 * [1582] 二进制矩阵中的特殊位置
 */

// @lc code=start
#include <stdbool.h>

int numSpecial(int** mat, int matSize, int* matColSize){
    int res = 0;
    for(int i=0;i<matSize;i++){
        bool fi = true;
        for(int j=0;j<*matColSize;j++){
            if(mat[i][j] == 1){
                bool f = true;
                for(int k=j+1;k<*matColSize;k++){
                    if(mat[i][k] == 1){
                        f = false;
                        fi = false;
                        break;
                    }
                }
                for(int k=0;k<matSize;k++){
                    if(mat[k][j] == 1 && k != i){
                        f = false;
                        break;
                    }
                }
                if(f){
                    res++;
                    fi = false;
                }
            }
            if(fi == false)break;
        }
    }
    return res;
}
// @lc code=end

