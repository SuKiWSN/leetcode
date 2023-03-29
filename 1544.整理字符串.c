/*
 * @lc app=leetcode.cn id=1544 lang=c
 *
 * [1544] 整理字符串
 */

// @lc code=start
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
char * makeGood(char * s){
    int len = strlen(s);
    int idx = 0;
    bool f = true;
    while(f){
        f = false;
        idx = 0;
        for(int i=0;s[i] != '\0';i++){
            if(abs(s[i] - s[i+1]) == 32){
                i++;
                f = true;
            }
            else{
                s[idx++] = s[i];
            }
        }
        s[idx] = '\0';
    }
    return s;
}
// @lc code=end

int main(){
    char s[100] = "abBAcC";
    printf("%s\n", makeGood(s));
    return 0;
}