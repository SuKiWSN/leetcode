/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isIsomorphic(char * s, char * t){
    int x[256], y[256];
    for(int i=0;i<256;i++){
        x[i] = -1;
        y[i] = -1;
    }
    for(int i=0;i<strlen(s);i++){
        // 一个字符只能映射到一个字符
        if(x[s[i]] == 1 && y[s[i]] != t[i])return false;
        x[s[i]] = 1;
        y[s[i]] = t[i]; 
    }
    // 一一对应
    for(int i=0;i<256;i++){
        for(int j=i+1;j<256;j++){
            if(y[i] == y[j] && y[i] != -1)return false;
        }
    }
    return true;
}
// @lc code=end

int main(){
    char s[100] = "egg";
    char t[100] = "add";
    printf("%d\n", isIsomorphic(s, t));
    return 0;
}