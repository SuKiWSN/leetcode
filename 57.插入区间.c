/*
 * @lc app=leetcode.cn id=57 lang=c
 *
 * [57] 插入区间
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int s;
    bool insert = false;
    int* res0;
    int** res = malloc(sizeof(int*)*(intervalsSize+1));
    *returnSize = 0;
    if(intervalsSize == 0){
        *returnSize = 1;
        *returnColumnSizes = malloc(sizeof(int)*1);
        returnColumnSizes[0][0] = 2;
        res[0] = newInterval;
        return res;
    }
    *returnColumnSizes = malloc(sizeof(int)*(intervalsSize+1));
    if(newInterval[1] < intervals[0][0]){
        *returnSize = 1;
        returnColumnSizes[0][0] = 2;
        res0 = malloc(sizeof(int)*2);
        res0[0] = newInterval[0];
        res0[1] = newInterval[1];
        res[0] = res0;
        insert = true;
    }
    for(s=0;s<intervalsSize;s++){
        if((insert == false && intervals[s][1] < newInterval[0]) || (insert == true)){
            res0 = malloc(sizeof(int)*2);
            res0[0] = intervals[s][0];
            res0[1] = intervals[s][1];
            returnColumnSizes[0][*returnSize] = 2;
            res[(*returnSize)++] = res0;
        }
        else if(insert == false && ((intervals[s][0] <= newInterval[0] && intervals[s][1] >= newInterval[0]) || (intervals[s][0] <= newInterval[1] && intervals[s][1] >= newInterval[1]))){
            if(intervals[s][1] >= newInterval[0]){
                res0 = malloc(sizeof(int)*2);
                res0[0] = intervals[s][0] < newInterval[0] ? intervals[s][0] : newInterval[0];
                for(;s<intervalsSize && intervals[s][1] < newInterval[1];s++);
                if(s == intervalsSize){
                    res0[1] = newInterval[1];
                }
                else if(intervals[s][0]<=newInterval[1]){
                    res0[1] = intervals[s][1];
                }
                else if(intervals[s][0] > newInterval[1]){
                    res0[1] = newInterval[1];
                    s--;
                }
                returnColumnSizes[0][*returnSize] = 2;
                res[(*returnSize)++] = res0;
                insert = true;
            }
        }
        else if(insert == false && (intervals[s][0] > newInterval[1])){
                res0 = malloc(sizeof(int)*2);
                res0[0] = newInterval[0];
                res0[1] = newInterval[1];
                returnColumnSizes[0][*returnSize] = 2;
                res[(*returnSize)++] = res0;
                insert = true;
                s--;
            }
    }
    if(insert == false){
        res0 = malloc(sizeof(int)*2);
        res0[0] = newInterval[0];
        res0[1] = newInterval[1];
        returnColumnSizes[0][*returnSize] = 2;
        res[(*returnSize)++] = res0;
    }
    return res;
}
// @lc code=end

