/*
 * @lc app=leetcode.cn id=1370 lang=c
 *
 * [1370] 上升下降字符串
 */

// @lc code=start
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// void fsort(char* str, int s, int e){
//     int i=s, j=e;
//     bool f = true;
//     while(s<e){
//         if(str[s] > str[e]){
//             int t = str[s];
//             str[s] = str[e];
//             str[e] = t;
//             f = !f;
//         }
//         if(f)s++;
//         else e--;
//     }
//     if(i != s)fsort(str, i, s-1);
//     if(j != s)fsort(str, s+1, j);
// }

char * sortString(char * s){
    int* word = malloc(sizeof(int) * 26);
    memset(word, 0, sizeof(int)*26);
    int len = strlen(s);
    for(int i=0;i<len;i++)word[s[i]-'a']++;
    char *res = malloc(sizeof(char)*(len+1));
    res[len] = '\0';
    int i = 0;
    while(i<len){
        for(int idx=0;idx<26;idx++){
            if(word[idx] > 0){
                word[idx]--;
                res[i++] = (char)(idx+ 'a');
            }
        }
        for(int idx=25;idx>=0;idx--){
            if(word[idx] > 0){
                word[idx]--;
                res[i++] = (char)(idx + 'a');
            }
        }
    }
    return res;
    // int len = strlen(s);
    // fsort(s, 0, len-1);
    // int i = 0;
    // char * res = malloc(sizeof(char)*(len+1));
    // res[len] = '\0';
    // int idx = 0;
    // while (i < len){
    //     int max = 0;
    //     for(idx = 0;idx<len;idx++){
    //         if(idx >= 0 && idx < len && s[idx] != '0' && s[idx]>max){
    //             res[i++] = s[idx];
    //             max = s[idx];
    //             s[idx] = '0';
    //         }
    //     }
    //     int min = 999;
    //     for(idx = len-1;idx>=0;idx--){
    //         if(idx>=0 && idx < len && s[idx] != '0' && s[idx]<min){
    //             res[i++] = s[idx];
    //             min = s[idx];
    //             s[idx] = '0';
    //         }
    //     }
    // }
    // return res;
}
// @lc code=end

int main(){
    char s[] = "aaaabbbbcccc";
    printf("%s\n", sortString(s));
    return 0;
}
