/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void trackback(char **array, int n, int push, int pop, int i, int *returnSize){
    static char str[17];
    str[2*n] = '\0';
    if(i == 2*n){
        char *p = (char*)malloc(sizeof(char)*(2*n+1));
        strcpy(p, str);
        if((*returnSize>0&&strcmp(str, array[*returnSize-1])!=0)||*returnSize == 0)array[(*returnSize)++] = p;
        return;
    }
    else{
        if(push < n){
            str[i++] = '(';
            trackback(array, n, ++push, pop, i, returnSize);
            i--;
            push--;
        }
        if(pop < push){
            str[i++] = ')';
            trackback(array, n, push, ++pop, i, returnSize);
            i--;
            pop--;
        }
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char **array;
    *returnSize = 0;
    array = (char**)malloc(sizeof(char*)*1430);
    trackback(array, n, 0, 0, 0, returnSize);
    return array;
}
// @lc code=end

int main(){
    int *returnSize = (int*)malloc(sizeof(int));
    char **array;
    array = generateParenthesis(3, returnSize);
    for(int i=0;i<returnSize[0];i++){
        printf("%s\n", array[i]);
    }
    return 0;
}
