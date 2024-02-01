/*
 * @lc app=leetcode.cn id=93 lang=c
 *
 * [93] 复原 IP 地址
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char* s, int* returnSize, int dotIdx, int i, char** res){
    static int seg[5] = {0, 0, 0, 0, 0};
    seg[4] = strlen(s);
    if(i == strlen(s)+1)return;
    if(dotIdx == 4){
        bool valid = true;
        for(int i=0;i<4;i++){
            if(s[seg[i]] == '0' && seg[i+1]-seg[i] != 1)return;
            long long t = 0;
            for(int j=seg[i];j<seg[i+1];j++){
                t += s[j] - '0';
                t *= 10;
            }
            if(t > 2550){
                valid = false;
                break;
            }
        }
        if(valid == true){
            char* p = malloc(sizeof(char) * (strlen(s) + 4));
            memset(p, '\0', sizeof(char)*(strlen(s)+4));
            int idx = 1;
            for(int i=0;i<strlen(s);i++){
                if(seg[idx] == i && idx <= 4){
                    p[i+idx-1] = '.';
                    idx++;
                }
                p[i+idx-1] = s[i];
            }
            res[(*returnSize)++] = p;
        }
        return;
    }
    seg[dotIdx] = i;
    backtrack(s, returnSize, dotIdx+1, i+1, res);
    backtrack(s, returnSize, dotIdx, i+1, res);
}
char** restoreIpAddresses(char* s, int* returnSize) {
    *returnSize = 0;
    char** res = malloc(sizeof(char*)*220);
    backtrack(s, returnSize, 1, 1, res);
    return res;
}
// @lc code=end

int main(){
    char* s = "0000";
    int* returnSize = malloc(sizeof(int));
    char** res = restoreIpAddresses(s, returnSize);
    for(int i=0;i<*returnSize;i++){
        printf("%s\n", res[i]);
    }
    return 0;
}