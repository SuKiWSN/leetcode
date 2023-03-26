/*
 * @lc app=leetcode.cn id=125 lang=c
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(char * s){
    int l = 0;
    while(s[l] != '\0')l++;
    int i=0, j=l-1;
    for(;i<l && j >= 0;){
        if((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9')){i++;continue;}
        if((s[j] < 'a' || s[j] > 'z') && (s[j] < 'A' || s[j] > 'Z') && (s[j] < '0' || s[j] > '9')){j--;continue;}
        if(((s[i] >='A' && s[i]<= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))&&((s[j] >='A' && s[j]<= 'Z') || (s[j] >= 'a' && s[j] <= 'z'))){
            if(s[i] == s[j] || s[i] == s[j]+32 || s[i] == s[j]-32){
                i++;
                j--;
                continue;
            }
            else return false;
        }
        else if(s[i] >= '0' && s[i] <= '9' && s[j] >= '0' && s[j] <= '9'){
            if(s[i] == s[j]){
                i++;
                j--;
                continue;
            }
            else return false;
        }
        else return false;
    }
    return true;
}
// @lc code=end

int main(){
    char *s = "0P";
    bool res = isPalindrome(s);
    printf("%d\n", res);
    return 0;
}