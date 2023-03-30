/*
 * @lc app=leetcode.cn id=1710 lang=c
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
#include <stdbool.h>

void fsort(int **arr, int s, int e){
    int i = s, j = e;
    bool f = true;
    while(s<e){
        if(arr[s][1] < arr[e][1]){
            int t = arr[s][1];
            arr[s][1] = arr[e][1];
            arr[e][1] = t;
            t = arr[s][0];
            arr[s][0] = arr[e][0];
            arr[e][0] = t;
            f = !f;
        }
        if(f)s++;
        else e--;
    }
    if(i != s)fsort(arr, i, s-1);
    if(j != s)fsort(arr, s+1, j);
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    fsort(boxTypes, 0, boxTypesSize-1);
    int i = 0;
    int res = 0;
    int idx = 0;
    while(i < truckSize && idx < boxTypesSize){
        res += (truckSize - i > boxTypes[idx][0]? boxTypes[idx][0] : truckSize - i) * boxTypes[idx][1];
        i += boxTypes[idx][0];
        idx++;
    }
    return res;
}
// @lc code=end

