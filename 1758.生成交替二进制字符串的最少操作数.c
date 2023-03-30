/*
 * @lc app=leetcode.cn id=1758 lang=c
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

int minOperations(char * s){
    int res = 0;
    bool f = true;
    for(int i=0;i<strlen(s);i++){
        if(f && s[i] == '1')res++;
        else if(!f && s[i] == '0')res++;
        f = !f;
    }
    return res < strlen(s) - res ? res : strlen(s) - res;
}
// @lc code=end

