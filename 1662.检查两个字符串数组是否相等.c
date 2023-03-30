/*
 * @lc app=leetcode.cn id=1662 lang=c
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
    char str[10001], str2[10001];
    memset(str, '\0', sizeof(char) * 10001);
    memset(str2, '\0', sizeof(char) * 10001);
    int idx = 0;
    for(int i=0;i<word1Size;i++){
        for(int j=0;j<strlen(word1[i]);j++){
            str[idx++] = word1[i][j];
        }
    }
    idx = 0;
    for(int i=0;i<word2Size;i++){
        for(int j=0;j<strlen(word2[i]);j++){
            str2[idx++] = word2[i][j];
        }
    }
    if(strcmp(str, str2) == 0)return true;
    else return false;
}
// @lc code=end

int main(){

    return 0;
}