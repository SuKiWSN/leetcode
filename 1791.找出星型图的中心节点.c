/*
 * @lc app=leetcode.cn id=1791 lang=c
 *
 * [1791] 找出星型图的中心节点
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

int findCenter(int** edges, int edgesSize, int* edgesColSize){
    int max = 0;
    int arg;
    int *arr = malloc(sizeof(int)*(100001));
    memset(arr, 0, sizeof(int)*(100001));
    for(int i=0;i<edgesSize;i++){
        arr[edges[i][0]]++;
        arr[edges[i][1]]++;
        for(int j=0;j<2;j++){
            if(arr[edges[i][j]] > max){
            max = arr[edges[i][j]];
            arg = edges[i][j];
            }
        }
    }
    return arg;
}
// @lc code=end

