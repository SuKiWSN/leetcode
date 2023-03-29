/*
 * @lc app=leetcode.cn id=1560 lang=c
 *
 * [1560] 圆形赛道上经过次数最多的扇区
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize){
    *returnSize = 0;
    int *record = malloc(sizeof(int) * n);
    int max = 0;
    int *res = malloc(sizeof(int) * n);

    memset(record, 0, sizeof(int) * n);
    record[rounds[0] % n]++;
    for(int i=1;i<roundsSize;i++){
        int e = rounds[i];
        if(rounds[i] < rounds[i-1])e += n;
        for(int j=rounds[i-1]+1;j<=e;j++){
            record[j % n]++;
            if(record[j%n] > max)max = record[j%n];
        }
    }
    for(int i=1;i<n;i++){
        if(record[i] == max){
            res[(*returnSize)++] = i%n?i:n;
        }
    }
    if(record[0] == max)res[(*returnSize)++] = n;
    return res;
}
// @lc code=end

int main(){
    int rounds[4] = {1, 3, 1, 2};
    int n = 4;
    int roundSize = sizeof(rounds) / sizeof(int);
    int *returnSize = malloc(sizeof(int));
    returnSize = mostVisited(n, rounds, roundSize, returnSize);
    return 0;
}
