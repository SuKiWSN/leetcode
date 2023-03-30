/*
 * @lc app=leetcode.cn id=1742 lang=c
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
int getn(int n){
    int res = 0;
    while(n){
        res += n%10;
        n /= 10;
    }
    return res;
}


int countBalls(int lowLimit, int highLimit){
    int max = 0;
    int arr[46] = {0};
    for(int i=lowLimit; i<=highLimit;i++){
        int p = getn(i);
        arr[p]++;
        if(arr[p] > max)max = arr[p];
    }
    return max;
}
// @lc code=end

