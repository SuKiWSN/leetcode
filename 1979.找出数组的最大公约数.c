/*
 * @lc app=leetcode.cn id=1979 lang=c
 *
 * [1979] 找出数组的最大公约数
 */

// @lc code=start
#include <stdbool.h>
#include <string.h>
void quicksort(int *a, int s, int e){
    int i=s, j=e;
    bool f = true;
    while(s<e){
        if(a[s] > a[e]){
            int t = a[s];
            a[s] = a[e];
            a[e] = t;
            f = !f;
        }
        if(f)s++;
        else e--;
    }
    if(s != i)quicksort(a, i, s-1);
    if(s != j)quicksort(a, s+1, j);
}

int findGCD(int* nums, int numsSize){
    // quicksort(nums, 0, numsSize-1);
    int min = __INT32_MAX__; 
    int max = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] > max)max = nums[i];
        if(nums[i] < min)min = nums[i];
    }
    int r = 0, a = max, b = min;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// @lc code=end

