/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// @lc code=start
int numDecodings(char* s){
    int f[strlen(s)+1];
    for(int i=0;i<=strlen(s);i++)f[i] = 0;
    f[0] = 1;
    for(int i=1;i<=strlen(s);i++){
        if(s[i-1] != '0'){
            f[i] = f[i-1];
        }
        if(i>=2){
            int t = (s[i-1]-'0') + (s[i-2]-'0')*10;
            if(t >= 10 && t <= 26)f[i] += f[i-2];
        }
    }
    return f[strlen(s)];
}
// @lc code=end

int main(){
    char s[3] = "10";
    printf("%d\n", numDecodings(s));
}