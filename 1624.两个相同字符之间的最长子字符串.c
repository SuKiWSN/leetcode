/*
 * @lc app=leetcode.cn id=1624 lang=c
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
#include <string.h>

int maxLengthBetweenEqualCharacters(char * s){
    int len = strlen(s);
    int max = -1;
    for(int i=0;i<len;i++){
        int t = -1;
        for(int j=i+1;j<len;j++){
            if(s[j] == s[i])t = j;
        }
        if(t != -1 && t-i-1 > max)max = t-i-1;
    }
    return max;
}
// @lc code=end

