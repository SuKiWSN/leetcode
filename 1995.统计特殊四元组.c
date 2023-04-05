/*
 * @lc app=leetcode.cn id=1995 lang=c
 *
 * [1995] 统计特殊四元组
 */

// @lc code=start


int countQuadruplets(int* nums, int numsSize){
    int arr[500] = {0}, res = 0;
    for(int i=numsSize-2;i>=2;i--){
        arr[nums[i+1]]++;
        for(int j=0;j<=i;j++){
            for(int k=j+1;k<i;k++){
                res += arr[nums[i] + nums[j] + nums[k]];
            }
        }
    }
    return res;
}
// @lc code=end

