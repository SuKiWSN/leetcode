/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quicksort(int* nums, int s, int e){
    int i = s, j = e;
    bool f = true;
    while(s<e){
        if(nums[s] > nums[e]){
            int t = nums[s];
            nums[s] = nums[e];
            nums[e] = t;
            f = !f;
        }
        if(f)s++;
        else e--;
    }
    if(s!=i)quicksort(nums, i, s-1);
    if(s!=j)quicksort(nums, s+1, j);
}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i=m;i<m+n;i++){
        nums1[i] = nums2[i-m];
    }
    quicksort(nums1, 0, m+n-1);
}
// @lc code=end

int main(){
    int a[] = {1,2,3,0,0,0};
    int b[] = {2, 5, 6};
    merge(a, 3,3, b,3, 3);
    for(int i=0;i<6;i++){
        printf("%d\n", a[i]);
    }
    return 0;
}