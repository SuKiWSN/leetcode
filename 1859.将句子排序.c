/*
 * @lc app=leetcode.cn id=1859 lang=c
 *
 * [1859] 将句子排序
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
bool isAnum(char c){
    if(c >= '0' && c <= '9')return true;
    else return false;
}

char * sortSentence(char * s){
    int len = strlen(s);
    char **arr = malloc(sizeof(char *) * 10);
    for(int i=0;i<10;i++){
        arr[i] = malloc(200);
        memset(arr[i], 0, 200);
    }
    for(int i=0;i<len;i++){
        int j=i;
        while(j < len && !isAnum(s[j]))j++;
        strncpy(arr[s[j] - '0'], s+i, j-i);
        i = j+1;
    }
    char * res = malloc(sizeof(char) * 200);
    memset(res, 0, 200);
    int idx = 0;
    for(int i=0;i<10;i++){
        if(arr[i][0] != '\0'){
            strcpy(res+idx, arr[i]);
            idx += strlen(arr[i]);
            res[idx++] = ' ';
        }
    }
    res[idx-1] = '\0';
    return res;
}
// @lc code=end
