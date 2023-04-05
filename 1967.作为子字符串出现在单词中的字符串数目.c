/*
 * @lc app=leetcode.cn id=1967 lang=c
 *
 * [1967] 作为子字符串出现在单词中的字符串数目
 */

// @lc code=start
#include <string.h>

int numOfStrings(char ** patterns, int patternsSize, char * word){
    int res = 0;
    for(int i=0;i<patternsSize;i++){
        if(strstr(word, patterns[i]))res++;
    }
    return res;
}
// @lc code=end

