/*
 * @lc app=leetcode.cn id=1688 lang=c
 *
 * [1688] 比赛中的配对次数
 */

// @lc code=start


int numberOfMatches(int n){
    int res = 0;
    while(n != 1){
        res += n / 2;
        n = n/2 + n%2;
    }
    return res;
}
// @lc code=end

