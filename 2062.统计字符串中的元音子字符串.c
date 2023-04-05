/*
 * @lc app=leetcode.cn id=2062 lang=c
 *
 * [2062] 统计字符串中的元音子字符串
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool inaeiou(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return true;
    else return false;
}

int countVowelSubstrings(char * word){
    int arr[26];
    int len = strlen(word);
    int res = 0;
    for(int i=0;i<len;i++){
        memset(arr, 0, sizeof(int)*26);
        int c = 0;
        for(int j=i;j<len;j++){
            if(inaeiou(word[j])){
                if(arr[word[j] - 'a'] == 0)c++;
                arr[word[j] - 'a']++;
                if(c == 5)res++;
            }
            else break;
        }
    }
    return res;
}
// @lc code=end

