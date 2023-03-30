/*
 * @lc app=leetcode.cn id=1748 lang=c
 *
 * [1748] 唯一元素的和
 */

// @lc code=start


int sumOfUnique(int* nums, int numsSize){
    int arr[101] = {0};
    for(int i=0;i<numsSize;i++){
        arr[nums[i]]++;
    }
    int res = 0;
    for(int i=0;i<101;i++){
        if(arr[i] == 1)res += i;
    }
    return res;
}
// @lc code=end

