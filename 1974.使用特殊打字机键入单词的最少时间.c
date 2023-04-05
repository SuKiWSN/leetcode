/*
 * @lc app=leetcode.cn id=1974 lang=c
 *
 * [1974] 使用特殊打字机键入单词的最少时间
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>

int minTimeToType(char * word){
    int res = 0;
    int len = strlen(word);
    char pos = 'a';
    for(int i=0;i<len;i++){
        int ltor = word[i] - pos < 0 ? word[i] + 26 - pos : word[i] - pos;
        int rtol = pos - word[i] < 0 ? pos + 26 - word[i] : pos - word[i];
        if(ltor < rtol)res += ltor+1;
        else res += rtol+1;
        pos = word[i];
    }
    return res;
}
// @lc code=end

