/*
 * @lc app=leetcode.cn id=1668 lang=c
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start
#include <string.h>
#include <stdio.h>

int maxRepeating(char * sequence, char * word){
    int res = 0;
    int max = 0;
    char *start = strstr(sequence, word);
    if(!start)return 0;
    while(strstr(start, word)){
        if(strstr(start, word) != start){
            if(strstr(start, word) == NULL)return max;
            else res = 0;
            start -= strlen(word);
            start += 1;
            start = strstr(start, word);
        }
        else{
            res++;
            if(res > max)max = res;
            start += strlen(word);
        }
    }
    return max;
}
// @lc code=end

int main(){
    char sequence[100] = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
    char word[100] = "aaaba";
    printf("%d\n", maxRepeating(sequence, word));
    return 0;
}