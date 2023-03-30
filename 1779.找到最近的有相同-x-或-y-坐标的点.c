/*
 * @lc app=leetcode.cn id=1779 lang=c
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
#include <stdlib.h>

int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize){
    int min = INT32_MAX;
    int arg = -1;
    for(int i=0;i<pointsSize;i++){
        if(points[i][0] == x || points[i][1] == y){
            int distance = abs(x-points[i][0]) + abs(y-points[i][1]);
            if(distance < min){
                min = distance;
                arg = i;
            }
        }
    }
    return arg;
}
// @lc code=end

