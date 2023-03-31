/*
 * @lc app=leetcode.cn id=1827 lang=c
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start


int minOperations(int* nums, int numsSize){
    if(numsSize == 1)return 0;
    int res = 0;
    for(int i=1;i<numsSize;i++){
        if(nums[i] <= nums[i-1]){
            res += nums[i-1] - nums[i] + 1;
            nums[i] = nums[i-1]+1;
        }
    }
    return res;
}
// @lc code=end

int main(){

}