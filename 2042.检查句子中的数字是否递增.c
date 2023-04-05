/*
 * @lc app=leetcode.cn id=2042 lang=c
 *
 * [2042] 检查句子中的数字是否递增
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool areNumbersAscending(char * s){
    int len = strlen(s);
    char *p = malloc(len+1);
    int a = -9999;
    for(int i=0;i<len;i++){
        while(i < len && s[i] < '0' || s[i] > '9')i++;
        if(i == len)break;
        int j = i;
        while(j < len && s[j] >= '0' && s[j] <= '9')j++;
        strncpy(p, s+i, j-i);
        p[j-i] = '\0';
        int t = atoi(p);
        if(t <= a)return false;
        else a = t;
        i = j;
    }
    return true;
}
// @lc code=end

int main(){
    char s[100] = "a 10 street 2 capital cities";
    printf("%d\n", areNumbersAscending(s));
    return 0;
}