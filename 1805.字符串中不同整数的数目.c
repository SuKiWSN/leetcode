/*
 * @lc app=leetcode.cn id=1805 lang=c
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// hash🐮🐮🐮
int gethash(char *str, int len){
    int res = 0;
    for(int i=0;i<len;i++){
        res *= 10;
        res += str[i] - '0';
        res %= 997;
    }
    return res;
}

int numDifferentIntegers(char * word){
    int res = 0;
    int len = strlen(word);
    int arr[1000] = {0};
    for(int i=0;i<len;i++){
        while(i < len && (word[i] < '0' || word[i] > '9'))i++;
        if(i < len){
            int j=i;
            while(j < len && word[j] >= '0' && word[j] <= '9')j++;
            int hash = gethash(word+i, j-i);
            if(arr[hash] == 0){
                res++;
                arr[hash] = 1;
            }
            i = j-1;
        }
    }
    return res;
}
// @lc code=end

int main(){
    char word[1000] = "4x324k324p324rp";
    printf("%d\n", numDifferentIntegers(word));
    return 0;
}