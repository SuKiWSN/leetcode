/*
 * @lc app=leetcode.cn id=1941 lang=c
 *
 * [1941] 检查是否所有字符出现次数相同
 */

// @lc code=start
#include <stdbool.h>


bool areOccurrencesEqual(char * s){
    int arr[26] = {0};
    for(int i=0;i<strlen(s);i++){
        arr[s[i]-'a']++;
    }
    int i=0, t;
    for(;i<26;i++){
        if(arr[i] != 0){
            t = arr[i];
            break;
        }
    }
    for(;i<26;i++){
        if(arr[i] != 0 && arr[i] != t)return false;
    }
    return true;
}
// @lc code=end

