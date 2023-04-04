/*
 * @lc app=leetcode.cn id=1897 lang=c
 *
 * [1897] 重新分配字符使所有字符串都相等
 */

// @lc code=start
#include <stdbool.h>
#include <string.h>

bool makeEqual(char ** words, int wordsSize){
    int arr[26] = {0};
    int t = 0;
    for(int i=0;i<wordsSize;i++){
        for(int j=0;j<strlen(words[i]);j++){
            arr[words[i][j] - 'a']++;
        }
    }
    int i=0;
    for(;i<26;i++){
        if(arr[i] % wordsSize != 0)return false;
    }
    return true;
}
// @lc code=end

