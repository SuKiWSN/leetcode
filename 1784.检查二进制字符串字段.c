/*
 * @lc app=leetcode.cn id=1784 lang=c
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool checkOnesSegment(char * s){
    int len = strlen(s);
    int res = 0;
    for(int i=0;i<len;i++){
        while(i < len && s[i] == '0')i++;
        if(i < len)res++;
        if(res > 1)return false;
        while(i < len && s[i] == '1')i++;
        i--;
    }
    return true;
}
// @lc code=end

