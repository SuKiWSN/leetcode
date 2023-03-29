/*
 * @lc app=leetcode.cn id=1446 lang=c
 *
 * [1446] 连续字符
 */

// @lc code=start

#include <stdio.h>
#include <string.h>

int maxPower(char * s){
    int len = strlen(s);
    int max = 1;
    int t = 1;
    for(int i=1;i<len;i++){
        if(s[i] == s[i-1]){
            t++;
            if(t > max)max = t;
        }
        else t = 1;
    }
    return max;
}
// @lc code=end

