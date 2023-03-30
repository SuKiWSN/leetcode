/*
 * @lc app=leetcode.cn id=1694 lang=c
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
#include <stdio.h>
#include <string.h>

char * reformatNumber(char * number){
    int i=0;
    int lenn = 0;
    while(i < strlen(number)){
        while(i < strlen(number) && (number[i] == '-' || number[i] == ' '))i++;
        if(i < strlen(number))number[lenn++] = number[i];
        i++;
    }
    number[lenn] = '\0';
    static char res[150];
    int idx = 0;
    i = 0;
    if(lenn >4)
    for(;i<lenn;i++){
        if(i%3 == 0 && i !=0){
            res[idx++] = '-';
            if(lenn - i <= 4)break;
        }
        res[idx++] = number[i];

    }
    if(lenn - i == 2){
        res[idx++] = number[lenn-2];
        res[idx++] = number[lenn-1];
    }
    else if(lenn - i == 3){
        res[idx++] = number[lenn -3];
        res[idx++] = number[lenn - 2];
        res[idx++] = number[lenn - 1];
    }
    else if(lenn - i == 4){
        res[idx++] = number[lenn-4];
        res[idx++] = number[lenn -3];
        res[idx++] = '-';
        res[idx++] = number[lenn - 2];
        res[idx++] = number[lenn - 1];
    }
    res[idx] = '\0';
    return res;
}
// @lc code=end

int main(){
    char number[100] = "--17-5 229 35-39475 ";
    char *res = reformatNumber(number);
    printf("%s\n", res);
}