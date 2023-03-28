/*
 * @lc app=leetcode.cn id=1408 lang=c
 *
 * [1408] 数组中的字符串匹配
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char ** stringMatching(char ** words, int wordsSize, int* returnSize){
    *returnSize = 0;
    short *tag = malloc(sizeof(short) * wordsSize);
    memset(tag, 0, sizeof(short) * wordsSize);
    char **res = malloc(sizeof(char*)*wordsSize);
    for(int i=0;i<wordsSize;i++){
        for(int j=0;j<wordsSize;j++){
            if(i != j && strstr(words[i], words[j]) && tag[j] == 0){
                *(res+(*returnSize)++) = words[j];
                tag[j] = 1;
            }
        }
    }
    return res;
}
// @lc code=end

