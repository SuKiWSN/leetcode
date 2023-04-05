/*
 * @lc app=leetcode.cn id=1945 lang=c
 *
 * [1945] 字符串转化后的各位数字之和
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getLucky(char * s, int k){
    int len = strlen(s);
    int t = 0;
    for(int i=0;i<len;i++){
        int r = s[i]-'a'+1;
        while(r){
            t += r%10;
            r /= 10;
        }
    }
    while(--k){
        int t1 = 0;
        while(t){
            t1 += t%10;
            t /= 10;
        }
        t = t1;
    }
    return t;
}
// @lc code=end

