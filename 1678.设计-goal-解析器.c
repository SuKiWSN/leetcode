/*
 * @lc app=leetcode.cn id=1678 lang=c
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char * interpret(char * command){
    static char res[101];
    int idx = 0;
    memset(res, '\0', 101);
    while(command[0] != '\0'){
        if(strstr(command, "G") == command){
            res[idx++] = 'G';
            command += 1;
        }
        else if(strstr(command, "()") == command){
            res[idx++] = 'o';
            command += 2;
        }
        else{
            res[idx++] = 'a';
            res[idx++] = 'l';
            command += 4;
        }
    }
    return res;
}
// @lc code=end

