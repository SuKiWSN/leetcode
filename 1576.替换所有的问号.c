/*
 * @lc app=leetcode.cn id=1576 lang=c
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
#include <string.h>

char * modifyString(char * s){
    if (s[0] == '?'){
        int t = 1;
        while(t<strlen(s) && s[t] == '?')t++;
        if(t == strlen(s))s[0] = 'a';
        else s[0] = (s[t]-'a'+1)%26 + 'a';
    }

    if (s[strlen(s)-1] == '?'){
        int t = strlen(s)-2;
        while(t >= 0 && s[t] == '?')t--;
        s[strlen(s)-1] = (s[t]-'a'+1)%26 + 'a';
    }
    for(int i=1;i<strlen(s)-1;i++){
        if(s[i] == '?'){
            int e = i+1;
            while(e<strlen(s) && s[e] == '?')e++;
            for(int j=0;j<26;j++){
                if('a' + j == s[i-1] || 'a' + j == s[e])continue;
                else{
                    s[i] = 'a' + j;
                    break;
                }
            }
        }
    }
    return s;
}
// @lc code=end

