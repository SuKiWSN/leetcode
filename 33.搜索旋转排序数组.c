/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start

//二分查找
int bisearch(int* nums, int s, int e, int target){
    int fs = s;
    if(nums[e] == target)return e;
    while(s < e){
        int z = nums[(s+e)/2];
        if(z == target) return (s+e)/2;
        else if(z > target)e = (s+e)/2;
        else{
            int t = s;
            s = (s+e)/2;
            if(s == fs)break;
            else fs = t;
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    int k=numsSize;
    if(k == 1){
        if(nums[0] == target) return 0;
        else return -1;
    }
    for(int i=1;i<numsSize;i++){
        if(nums[i] < nums[i-1]){
            k = i;
            break;
        }
    }
    int res = -1;
    if(k-1 >= 0 && target >= nums[0] && target <= nums[k-1])res = bisearch(nums, 0, k-1, target);
    else if(k < numsSize && target >= nums[k] && target <= nums[numsSize-1])res = bisearch(nums, k, numsSize-1, target);
    return res;
}
// @lc code=end

