/*
 * @lc app=leetcode.cn id=38 lang=c
 *
 * [38] 外观数列
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#define MAX 5000

char * countAndSay(int n){
    int i = 1;
    char *t = (char *)malloc(sizeof(char)*MAX);
    char * res = (char *)malloc(sizeof(char)*MAX);
    memset(t, '\0', MAX);
    t[0] = '1';
    memset(res, '\0', MAX);
    res[0] = '1';
    while(i < n){
        int ind = 0;
        for(int j=0;t[j] != '\0';j++){
            char c = t[j];
            int k = 1;
            while(t[j+1] != '\0' && t[j+1] == t[j]){
                k++;
                j++;
            }
            res[ind++] = k + '0';
            res[ind++] = c;
        }
        strcpy(t, res);
        i++;
    }
    return res;
}
// @lc code=end

