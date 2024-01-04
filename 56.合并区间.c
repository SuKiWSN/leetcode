/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
void quicksort(int** intervals, int s, int e){
    int i = s, j = e;
    bool f = true;
    while(s < e){
        if(intervals[s][0] > intervals[e][0]){
            int t1 = intervals[s][0];
            int t2 = intervals[s][1];
            intervals[s][0] = intervals[e][0];
            intervals[s][1] = intervals[e][1];
            intervals[e][0] = t1;
            intervals[e][1] = t2;
            f = !f;
        }
        if(f)e--;
        else s++;
    }
    if(i != s)quicksort(intervals, i, s-1);
    if(j != s)quicksort(intervals, s+1, j);
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int** res = malloc(sizeof(int*)*intervalsSize);
    *returnColumnSizes = malloc(sizeof(int)*intervalsSize);
    quicksort(intervals, 0, intervalsSize-1);
    *returnSize = 0;
    int* res0 = malloc(sizeof(int)*2);
    res0[0] = intervals[0][0];
    res0[1] = intervals[0][1];
    for(int i=1;i<intervalsSize;i++){
        if(intervals[i][0] <= res0[1]){
            res0[1] = res0[1] > intervals[i][1] ? res0[1] : intervals[i][1];
        }
        else{
            returnColumnSizes[0][*returnSize] = 2;
            res[(*returnSize)++] = res0;
            res0 = malloc(sizeof(int)*2);
            res0[0] = intervals[i][0];
            res0[1] = intervals[i][1];
        }
    }
    returnColumnSizes[0][*returnSize] = 2;
    res[(*returnSize)++] = res0;
    return res;
}
// @lc code=end
