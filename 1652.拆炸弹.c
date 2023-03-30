/*
 * @lc app=leetcode.cn id=1652 lang=c
 *
 * [1652] 拆炸弹
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* decrypt(int* code, int codeSize, int k, int* returnSize){
    int * res = malloc(sizeof(int)*codeSize);
    *returnSize = codeSize;
    memset(res, 0, sizeof(int)*codeSize);
    if(k == 0)return res;
    else if(k > 0){
        for(int i=0;i<codeSize;i++){
            for(int j=1;j<=k;j++){
                res[i] += code[(i+j)%codeSize];
            }
        }
    }
    else{
        for(int i=0;i<codeSize;i++){
            for(int j=1;j<=abs(k);j++){
                res[i] += i-j < 0? code[(i-j)%codeSize+codeSize]: code[i-j];
            }
        }
    }
    return res;
}
// @lc code=end

int main(){

}