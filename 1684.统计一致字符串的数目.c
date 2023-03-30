/*
 * @lc app=leetcode.cn id=1684 lang=c
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    bool word[26] = {0};
    memset(word, 0, sizeof(word));
    for(int i=0;i<strlen(allowed);i++){
        word[allowed[i]-'a'] = true;
    }
    int res = 0;
    for(int i=0;i<wordsSize;i++){
        bool f = true;
        for(int j=0;j<strlen(words[i]);j++){
            if(word[words[i][j] - 'a'] == false){
                f = false;
                break;
            }
        }
        if(f)res++;
    }
    return res;
}
// @lc code=end

