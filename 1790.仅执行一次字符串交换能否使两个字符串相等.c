/*
 * @lc app=leetcode.cn id=1790 lang=c
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
#include <stdbool.h>
#include <string.h>

bool areAlmostEqual(char * s1, char * s2){
    int c = 0;
    
    while(c<strlen(s1) && s1[c] == s2[c])c++;
    if(c == strlen(s1))return true;
    for(int i=c;i<strlen(s2);i++){
        if(s1[i] == s2[c]){
            s1[i] = s1[c];
            s1[c] = s2[c];
            if(!strcmp(s1, s2))return true;
            else{
                s1[c] = s1[i];
                s1[i] = s2[c];
            }
        }
    }
    return false;
}
// @lc code=end

