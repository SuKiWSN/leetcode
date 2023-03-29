/*
 * @lc app=leetcode.cn id=1496 lang=c
 *
 * [1496] 判断路径是否相交
 */

// @lc code=start
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int gethash(int x, int y){
    return (x+113) * (x+113) + y+113;
}

bool isPathCrossing(char * path){
    int hashlist[40000] = {0};
    int len = strlen(path);
    int x = 0, y = 0;
    hashlist[gethash(x, y)] = 1;
    for(int i=0;i<len;i++){
        if(path[i] == 'N')y++;
        else if(path[i] == 'E')x++;
        else if(path[i] == 'S')y--;
        else x--;
        int hash = gethash(x, y);
        if(hashlist[hash])return true;
        else hashlist[hash] = 1;
    }
    return false;
}
// @lc code=end

int main(){
    char path[100] = "NESWW";
    printf("%d\n", isPathCrossing(path));
    return 0;
}