/*
 * @lc app=leetcode.cn id=258 lang=c
 *
 * [258] 各位相加
 */

// @lc code=start


int addDigits(int num){
    int res = 0;
    while(num >= 10){
        while(num){
            res += num % 10;
            num /= 10;
        }
        num = res;
        res = 0;
    }
    return num;
}
// @lc code=end

