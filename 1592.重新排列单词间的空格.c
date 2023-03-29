/*
 * @lc app=leetcode.cn id=1592 lang=c
 *
 * [1592] 重新排列单词间的空格
 */

// @lc code=start
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * reorderSpaces(char * text){
    int numw = 0, numb = 0, len = strlen(text);
    char * res = malloc(sizeof(char) * (len+1));
    memset(res, ' ', len+1);
    res[len] = '\0';

    for(int i=0;i<len;i++){
        while(i < len && text[i] == ' '){
            numb++;
            i++;
        }
        while(i < len && text[i] >= 'a' && text[i] <= 'z'){
            i++;
        }
        if(i < len || (i == len && text[i-1] >= 'a' && text[i-1] <= 'z'))numw++;
        i--;
    }
    int idx = 0;
    for(int i=0;i<len;i++){
        while(i<len && text[i] == ' ')i++;
        while(i<len && text[i] != ' '){
            res[idx++] = text[i++];
        }
        if(numw == 1)break;
        idx += numb / (numw-1);
    }
    return res;
}
// @lc code=end
int main(){
    char text[100] = "  this   is  a sentence ";
    char *t = reorderSpaces(text);
    return 0;
}
