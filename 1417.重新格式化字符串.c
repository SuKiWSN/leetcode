/*
 * @lc app=leetcode.cn id=1417 lang=c
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reformat(char * s){
    char * res = malloc(sizeof(char) * (strlen(s)+1));
    res[0] = '\0';
    res[strlen(s)] = '\0';
    int lenc = 0;
    int lenn = 0;
    int i = 0;
    for(int i=0;i<strlen(s);i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            lenc++;
        }
        else lenn++;
    }
    if(abs(lenc - lenn) > 1)return res;
    int ic = 0, in = 0;
    int idx = 0;
    if(lenc > lenn){
        while(idx < strlen(s)){
            while(ic < strlen(s) && s[ic] < 'a' || s[ic] > 'z')ic++;
            if(idx < strlen(s))res[idx++] = s[ic++];
            while(in < strlen(s) && s[in] < '0' || s[in] > '9')in++;
            if(idx < strlen(s))res[idx++] = s[in++];
        }
    }
    else{
        while(idx < strlen(s)){
            while(ic < strlen(s) && (s[ic] < '0' || s[ic] > '9'))ic++;
            if(idx < strlen(s))res[idx++] = s[ic++];
            while(in < strlen(s) && (s[in] < 'a' || s[in] > 'z'))in++;
            if(idx < strlen(s))res[idx++] = s[in++];
        }
    }
    return res;
}
// @lc code=end

int main(){
    char s[256] = "ab123";
    char *res = reformat(s);
    printf("%s\n", res);
    return 0;
}
