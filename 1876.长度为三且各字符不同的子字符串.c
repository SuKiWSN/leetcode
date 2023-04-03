/*
 * @lc app=leetcode.cn id=1876 lang=c
 *
 * [1876] 长度为三且各字符不同的子字符串
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>

int countGoodSubstrings(char * s){
    int len = strlen(s);
    if(len == 1)return 0;
    else if(len == 2)return s[0] != s[1] ? 1 : 0;
    char *p = malloc(4);
    int res = 0;
    for(int i=0;i<len-2;i++){
        strncpy(p, s+i, 3);
        p[3] = '\0';
        bool f = true;
        for(int j=0;j<2;j++){
            if(strchr(p+j+1, p[j]))f = false;
        }
        if(f)res++;
    }
    return res; 
}
// @lc code=end

