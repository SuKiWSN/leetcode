/*
 * @lc app=leetcode.cn id=1880 lang=c
 *
 * [1880] 检查某单词是否等于两单词之和
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int a2i(char *s){
    int res = 0;
    for(int i=0;i<strlen(s);i++){
        res *= 10;
        res += s[i]-'a';
    }
    return res;
}

bool isSumEqual(char * firstWord, char * secondWord, char * targetWord){
    int c = 0;
    return a2i(firstWord) + a2i(secondWord) == a2i(targetWord);
}
// @lc code=end

