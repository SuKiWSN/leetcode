/*
 * @lc app=leetcode.cn id=1385 lang=c
 *
 * [1385] 两个数组间的距离值
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fastsort(int**a, int s, int e){
    int i = s, j = e;
    bool f = true;
    while(s<e){
        if(a[0][s] > a[0][e]){
            int t = a[0][s];
            a[0][s] = a[0][e];
            a[0][e] = t;
            t = a[1][s];
            a[1][s] = a[1][e];
            a[1][e] = t;
            f = !f;
        }
        if(f)s++;
        else e--;
    }
    if(i!=s)fastsort(a, i, s-1);
    if(j!=s)fastsort(a, s+1, j);
}

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d){

    // 暴力
    int res = 0;
    for(int i=0;i<arr1Size;i++){
        bool f = true;
        for(int j=0;j<arr2Size;j++){
            if(abs(arr1[i] - arr2[j]) <= d)f = false;
        }
        if(f)res++;
    }
    return res;
}
// @lc code=end

