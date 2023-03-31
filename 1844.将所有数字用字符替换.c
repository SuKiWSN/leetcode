/*
 * @lc app=leetcode.cn id=1844 lang=c
 *
 * [1844] 将所有数字用字符替换
 */

// @lc code=start
#include <string.h>

char * replaceDigits(char * s){
    int len = strlen(s);
    for(int i=1;i<len;i+=2){
        s[i] = s[i]+s[i-1]-'0';
    }
    return s;
}
// @lc code=end

