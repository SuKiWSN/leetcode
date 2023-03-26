/*
 * @lc app=leetcode.cn id=1332 lang=c
 *
 * [1332] 删除回文子序列
 */

// @lc code=start
#include <stdio.h>
#include <string.h>

int removePalindromeSub(char * s){
    int l = strlen(s);
    for(int i=0;i<l/2;i++){
        if(s[i] != s[l-i-1])return 2;
    }
    return 1;
}
// @lc code=end

