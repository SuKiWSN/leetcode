/*
 * @lc app=leetcode.cn id=1646 lang=c
 *
 * [1646] 获取生成数组中的最大值
 */

// @lc code=start


int getMaximumGenerated(int n){
    int max=1;
    int *arr = malloc(sizeof(int) *(n+1));
    if(n==0)return 0;
    arr[0] = 0;
    arr[1] = 1;
    for(int i=1;i<(n+1)/2;i++){
        if(2*i>=2&& 2*i<=n){
            arr[2*i] = arr[i];
        }
        if(2*i+1 >= 2 && 2*i+1 <= n){
            arr[2*i+1] = arr[i] + arr[i+1];
            if(arr[2*i+1] > max)max = arr[2*i+1];
        }
    }
    return max;
}
// @lc code=end

