/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stdio.h>
void qsort(int* array, int s, int e){
    int i = s, j = e;
    bool f = true;
    while(s < e){
        if(array[s] > array[e]){
            int t = array[s];
            array[s] = array[e];
            array[e] = t;
            f = !f;
        }
        if(f)e--;
        else s++;
    }
    if(s != i) qsort(array, i, s-1);
    if(s != j) qsort(array, s+1, j);
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, 0, numsSize-1);
    *returnSize = 0;
    
}
// @lc code=end

int main(){
    int array[5] = {4, 2, 6, 8, 1};
    qsort(array, 0, 4);
    for(int i=0;i<5;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}