/*
 * @lc app=leetcode.cn id=89 lang=c
 *
 * [89] 格雷编码
 */
#include <stdlib.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int* res = malloc(sizeof(int)*1<<n);
    *returnSize = 1<<n;
    for(int i=0;i<1<<n;i++){
        res[i] = i ^ (i>>1);// 第i个格雷码 = i ^ (i << 1)
    }
    return res;
}
// @lc code=end

