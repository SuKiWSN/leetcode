/*
 * @lc app=leetcode.cn id=1539 lang=c
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
#include <stdio.h>
int findKthPositive(int* arr, int arrSize, int k){
    int res = 1;
    int i = 0;
    while(k > 0){
        while(i < arrSize && arr[i] != res++){
            k--;
            if(k <= 0)break;
        }
        i++;
        if(i >= arrSize)break;
    }
    for(int i=0;i<k;i++)res++;
    return res-1;
}
// @lc code=end
int main(){
    int arr[] =  {2, 3, 4, 7, 11};
    int k = 5;
    printf("%d\n", findKthPositive(arr, sizeof(arr)/sizeof(int), k));
    return 0;
}