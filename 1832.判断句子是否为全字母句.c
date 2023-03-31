/*
 * @lc app=leetcode.cn id=1832 lang=c
 *
 * [1832] 判断句子是否为全字母句
 */

// @lc code=start
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool checkIfPangram(char * sentence){
    bool arr[26];
    memset(arr, 0, 26);
    int c = 0;
    for(int i=0;i<strlen(sentence);i++){
        if(!arr[sentence[i]-'a']){
            arr[sentence[i] - 'a'] = true;
            c++;
            if(c == 26)return true;
        }
    }
    return false;
}
// @lc code=end

int main(){
    printf("%d\n", sizeof(int));
    return 0;
}