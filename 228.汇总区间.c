/*
 * @lc app=leetcode.cn id=228 lang=c
 *
 * [228] 汇总区间
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char* itoa(int n){
    static char res[21] = {0};
    int i = 0;
    while(n){
        res[19-i] = n%10+'0';
        n /= 10;
        i++;
    }
    char *p;
    p = res+20-i;
    return p;
}

char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    char **res;
    *returnSize = 0;
    res = malloc(sizeof(char *) * 20);
    *res = itoa(nums[0]);
    int idx = 0;
    for(int i=1;i<numsSize;i++){
        while(nums[i] == nums[i-1]+1)i++;
        res[idx] = malloc(21);
        memset(res, 0, 21);
        res[idx][]
    }
}
// @lc code=end

int main(){
    int i=10;
    char * res = itoa(i);
    printf("%s\n", res);
    return 0;
}