/*
 * @lc app=leetcode.cn id=1436 lang=c
 *
 * [1436] 旅行终点站
 */

// @lc code=start
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 

char * destCity(char *** paths, int pathsSize, int* pathsColSize){
    for(int i=0;i<pathsSize;i++){
        bool f = true;
        for(int j=0;j<pathsSize;j++){
            if(strcmp(paths[i][1], paths[j][0]) == 0){
                f = false;
                break;
            }
        }
        if(f)return paths[i][1];
    }
    return paths[1][0];
}
// @lc code=end

