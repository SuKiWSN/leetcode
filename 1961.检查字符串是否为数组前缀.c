/*
 * @lc app=leetcode.cn id=1961 lang=c
 *
 * [1961] 检查字符串是否为数组前缀
 */

// @lc code=start
#include <stdbool.h>
#include <string.h>

bool isPrefixString(char * s, char ** words, int wordsSize){
    int len = strlen(s);
    int idx = 0;
    for(int i=0;i<wordsSize;i++){
        if(strstr(s+idx, words[i]) == s+idx){
            idx += strlen(words[i]);
            if(idx == len)return true;
        }
        else return false;
    }
    return false;
}
// @lc code=end

