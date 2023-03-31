/*
 * @lc app=leetcode.cn id=1812 lang=c
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lc code=start
#include <stdbool.h>

bool squareIsWhite(char * coordinates){
    int x = coordinates[0] - 'a';
    int y = coordinates[1] - '0';
    if(x % 2 == 0){
        if(y % 2 == 0)return true;
        else return false;
    }
    else{
        if(y % 2 == 0)return false;
        else return true;
    }
}
// @lc code=end

