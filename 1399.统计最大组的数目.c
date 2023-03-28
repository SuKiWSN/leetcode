/*
 * @lc app=leetcode.cn id=1399 lang=c
 *
 * [1399] 统计最大组的数目
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int e(int n){
    int res = 0;
    while(n){
        res += n%10;
        n/=10;
    }
    return res;
}

int countLargestGroup(int n){
    int *arr = malloc(sizeof(int)*37);
    int max = 0, res = 0;
    memset(arr, 0, sizeof(int)*37);
    for(int i=1;i<=n;i++){
        int t = e(i);
        arr[t]++;
        if(arr[t] > max)max = arr[t];
    }
    for(int i=1;i<=36;i++){
        if(arr[i] == max)res++;
    }
    return res;
}
// @lc code=end

