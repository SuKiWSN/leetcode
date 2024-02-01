/*
 * @lc app=leetcode.cn id=128 lang=c
 *
 * [128] 最长连续序列
 */
#include <stdlib.h>
#include <stdio.h>
// @lc code=start
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int longestConsecutive(int* nums, int numsSize) {
    if(numsSize == 0)return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = 1;
    int max = 1;
    for(int i=1;i<numsSize;i++){
        if(nums[i] - nums[i-1] == 1)res++;
        else if(nums[i] == nums[i-1])continue;
        else res = 1;
        if(res > max)max = res;
    }
    return max;
}
// @lc code=end

int main(){
    int num[4] = {1, 2, 0, 1};
    int* nums = malloc(sizeof(int)*4);
    for(int i=0;i<4;i++)nums[i] = num[i];
    int numsSize = 4;
    printf("%d\n", longestConsecutive(nums, numsSize));
    return 0;
}