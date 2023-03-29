/*
 * @lc app=leetcode.cn id=1455 lang=c
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int isPrefixOfWord(char * sentence, char * searchWord){
    int res = 1;
    int len = strlen(sentence);
    for(int i=0;i<len;i++){
        if(strstr(sentence+i, searchWord) == sentence+i)return res;
        else{
            while(i<len && sentence[i] != ' ')i++;
            res++;
        }
    }
    return -1;
}
// @lc code=end

int main(){
    // char * sentence = "i love eating burger";
    // printf("%d\n", isPrefixOfWord(sentence, "burg"));
    char s[10] = "123455";
    printf("%d\n", strstr(s, "123"));
    return 0;
}