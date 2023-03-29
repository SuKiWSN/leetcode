/*
 * @lc app=leetcode.cn id=1512 lang=c
 *
 * [1512] 好数对的数目
 */

// @lc code=start
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int numIdenticalPairs(int* nums, int numsSize){
    int res = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int t = 1;
    for(int i=1;i<numsSize;i++){
        if(nums[i] == nums[i-1])t++;
        else{
            res += t*(t-1)/2;
            t = 1;
        }
    }
    if(t >= 2)res += t*(t-1)/2;
    return res;
}
// @lc code=end

