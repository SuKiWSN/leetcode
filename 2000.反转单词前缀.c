/*
 * @lc app=leetcode.cn id=2000 lang=c
 *
 * [2000] 反转单词前缀
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char * reversePrefix(char * word, char ch){
    char * pos = malloc(1);
    pos = strchr(word, ch);
    for(int i=0;i<(pos-word+1)/2;i++){
        char c = word[i];
        word[i] = word[pos-word-i];
        word[pos-word-i] = c;
    }
    return word;
}
// @lc code=end

int main(){
    char word[100] = "abcdefd";
    char ch = 'd';
    char *res = reversePrefix(word, ch);
    printf("%s\n", res);
    return 0;
}
