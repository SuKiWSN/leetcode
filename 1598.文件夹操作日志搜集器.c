/*
 * @lc app=leetcode.cn id=1598 lang=c
 *
 * [1598] 文件夹操作日志搜集器
 */

// @lc code=start
#include <string.h>

int minOperations(char ** logs, int logsSize){
    int res = 0;
    for(int i=0;i<logsSize;i++){
        if(!strcmp(logs[i], "../"))res = res>0?res-1:0;
        else if(!strcmp(logs[i], "./"))continue;
        else res++;
    }
    return res;
}
// @lc code=end

