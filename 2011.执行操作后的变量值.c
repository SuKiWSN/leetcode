/*
 * @lc app=leetcode.cn id=2011 lang=c
 *
 * [2011] 执行操作后的变量值
 */

// @lc code=start
#include <string.h>

int finalValueAfterOperations(char ** operations, int operationsSize){
    int x = 0;
    for(int i=0;i<operationsSize;i++){
        if(!strcmp(operations[i], "++X") || !strcmp(operations[i], "X++"))x++;
        else x--;
    }
    return x;
}
// @lc code=end

