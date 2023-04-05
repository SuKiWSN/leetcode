/*
 * @lc app=leetcode.cn id=2027 lang=c
 *
 * [2027] 转换字符串的最少操作次数
 */

// @lc code=start
#include <string.h>

int minimumMoves(char * s){
    int len = strlen(s), res = 0;
    for(int i=0;i<len;i++){
        if(s[i] == 'X'){
            res++;
            i += 2;
        }
    }
    return res;
}
// @lc code=end

