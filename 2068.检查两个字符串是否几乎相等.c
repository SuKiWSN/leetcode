/*
 * @lc app=leetcode.cn id=2068 lang=c
 *
 * [2068] 检查两个字符串是否几乎相等
 */
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
// @lc code=start

bool checkAlmostEquivalent(char * word1, char * word2){
    int arr1[26] = {0};
    int arr2[26] = {0};
    for(int i=0;i<strlen(word1);i++)arr1[word1[i]- 'a']++;
    for(int i=0;i<strlen(word2);i++)arr2[word2[i]- 'a']++;
    for(int i=0;i<26;i++){
        if(abs(arr1[i] - arr2[i]) > 3)return false;
    }
    return true;
}
// @lc code=end

