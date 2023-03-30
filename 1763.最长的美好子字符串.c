/*
 * @lc app=leetcode.cn id=1763 lang=c
 *
 * [1763] 最长的美好子字符串
 */

// @lc code=start
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/*
Your runtime beats 100 % of c submissions
Your memory usage beats 51.43 % of c submissions (5.5 MB)
*/

// 分治法
void dfs(char *str, int s, int e, char *res, int *max){
    if(s >= e)return;
    bool f = true;
    int i;
    for(i=s;i<=e;i++){
        // 查找str[i]对应的大写(小写)字符是否存在,若存在还要判断字符是否落在s ~ e区间内
        char *pos = strchr(str+s, str[i] <= 'Z' ? str[i]+32 : str[i]-32);
        if(!(pos && pos <= str+e)){
            f = false;
            break;
        }
    }
    if(!f){
        // 如果str[i] 在str[s~e]内为非法字符,则递归处理左部和右部,先处理左部因为题目要求返回先出现的结果
        dfs(str, s, i-1, res, max);
        dfs(str, i+1, e, res, max);
    }
    else{
        // 如果str[s~e]是一个完美字符串,判断其长度是否符合题意,若符合则替换res
        if(e-s+1 > *max){
            *max = e-s+1;
            for(int i=s;i<=e;i++){
                res[i-s] = str[i];
            }
        }
    }
}

char * longestNiceSubstring(char * s){
    int *max = malloc(sizeof(int));
    *max = 0;
    char *res = malloc(sizeof(char) * (strlen(s)+1));
    memset(res, '\0', sizeof(char) * (strlen(s)+1));
    dfs(s, 0, strlen(s)-1, res, max);
    return res;
}
// @lc code=end

int main(){
    char str[100] = "dDzeE";
    char *res = longestNiceSubstring(str);
    printf("%s\n", res);
    return 0;
}