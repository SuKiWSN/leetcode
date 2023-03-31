/*
 * @lc app=leetcode.cn id=1854 lang=c
 *
 * [1854] 人口最多的年份
 */

// @lc code=start
#include <stdio.h>

int maximumPopulation(int** logs, int logsSize, int* logsColSize){
    int arr[100] = {0};
    int max = 0, min = 2050;
    for(int i=0;i<logsSize;i++){
        for(int j=logs[i][0]-1950;j<logs[i][1]-1950;j++){
            arr[j]++;
            if(arr[j]>max || (arr[j]==max&&j+1950<min)){
                max = arr[j];
                min = j+1950;
            }
        }
    }
    return min;
}
// @lc code=end

