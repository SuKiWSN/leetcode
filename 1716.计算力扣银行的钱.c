/*
 * @lc app=leetcode.cn id=1716 lang=c
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start


int totalMoney(int n){
    int s = 0;
    int res = 0;
    for(int i=0;i<n;i++){
        if(i%7 == 0)s++;
        res += (s + i%7);
    }
    return res;
}

// @lc code=end

