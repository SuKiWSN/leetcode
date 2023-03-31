/*
 * @lc app=leetcode.cn id=1816 lang=c
 *
 * [1816] 截断句子
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>

char * truncateSentence(char * s, int k){
    short len = strlen(s);
    short i = 0;
    while(k--){
        while(i < len && s[i] != ' ')i++;i++;
    }
    s[i-1] = '\0';
    return s;
}
// @lc code=end

