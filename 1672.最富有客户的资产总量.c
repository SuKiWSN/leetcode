/*
 * @lc app=leetcode.cn id=1672 lang=c
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start


int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int max = 0;
    for(int i=0;i<accountsSize;i++){
        int t = 0;
        for(int j=0;j<*accountsColSize;j++){
            t += accounts[i][j];
        }
        if(t > max)max = t;
    }
    return max;
}
// @lc code=end

