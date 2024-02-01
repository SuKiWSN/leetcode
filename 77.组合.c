/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
 */
#include <stdlib.h>
#include <stdio.h>
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int n, int k, int* returnSize, int** ans, int th, int idx){
    if(idx > n+1)return;
    static int r1[20] = {0};
    if(th == k){
        int* r2 = malloc(sizeof(int)*k);
        for(int i=0;i<k;i++)r2[i] = r1[i];
        ans[(*returnSize)++] = r2;
        return;
    }
    r1[th] = idx;
    if(th+n-idx+1 >= k)backtrack(n, k, returnSize, ans, th+1, idx+1);
    if(th+n-idx >=k)backtrack(n, k, returnSize, ans, th, idx+1);
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int)* 500000);
    int** ans = malloc(sizeof(int*)* 500000);
    backtrack(n, k, returnSize, ans, 0, 1);
    for(int i=0;i<*returnSize;i++)returnColumnSizes[0][i] = k;
    return ans;
}
// @lc code=end

int main(){
    int n = 20, k = 10;
    int* returnSize = malloc(sizeof(int));
    int** returnColumnSizes = malloc(sizeof(int*));
    int** ans = combine(n, k, returnSize, returnColumnSizes);
    printf("%d\n", *returnSize);
    return 0;
}