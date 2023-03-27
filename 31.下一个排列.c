/*
 * @lc app=leetcode.cn id=31 lang=c
 *
 * [31] 下一个排列
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ismax(int *nums, int l){
    for(int i=0;i<l-1;i++){
        if(nums[i]<nums[i+1])return false;
    }
    return true;
}



void nextPermutation(int* nums, int numsSize){
    for(int i=0;i<numsSize;i++){
        if(ismax(nums+i, numsSize-i) && i == numsSize-1){
            if(i == 0)break;
            int t = nums[i];
            nums[i] = nums[i-1];
            nums[i-1] = t;
            break;
        }
        if(ismax(nums+i, numsSize-i)){
            if(i == 0){
                for(int j=0;j<numsSize / 2;j++){
                    int t = nums[j];
                    nums[j] = nums[numsSize-j-1];
                    nums[numsSize-j-1] = t;
                }
                break;
            }
            else{
                int j = i;
                while(j < numsSize && nums[j] > nums[i-1])j++;
                int t = nums[j-1];
                nums[j-1] = nums[i-1];
                nums[i-1] = t;
                for(int k=i;k<(numsSize+i+1)/2;k++){
                    int t1 = nums[k];
                    nums[k] = nums[numsSize-k+i-1];
                    nums[numsSize-k+i-1] = t1;
                }
                break;
            }
        }
    }
}
// @lc code=end

int main(){
    int nums[] = {1, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    nextPermutation(nums, numsSize);
    for(int i=0;i<numsSize;i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}