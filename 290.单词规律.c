/*
 * @lc app=leetcode.cn id=290 lang=c
 *
 * [290] 单词规律
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
bool wordPattern(char * pattern, char * s){
    int count_blank = 1;
    for(int i=0;i<strlen(s);i++){
        if (s[i] == ' ')count_blank++;
    }
    if(strlen(s) == 0)count_blank = 0;
    if(strlen(pattern) != count_blank)return false;
    int hash[26], j=0;
    memset(hash, 0, sizeof(hash));
    for(int i=0;i<strlen(pattern);i++){
        int t = 0;
        while(s[j] != ' ' && s[j] != '\0'){
            t = (t*3 + s[j])%100000007;
            j++;
        }
        j++;
        if (hash[pattern[i] - 'a'] == 0){
            hash[pattern[i] - 'a'] = t;
        }
        else{
            if (hash[pattern[i] - 'a'] != t){
                return false;
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=i+1;j<26;j++){
            if(hash[j] != 0 && hash[j] == hash[i])return false;
        }
    }
    return true;
}
// @lc code=end

