/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int min = 20000;
    for(int i=0;i<pricesSize;i++){
        if(prices[i] < min)min = prices[i];
        else{
            profit += prices[i]-min;
            min = prices[i];
        }
    }
    return profit;
}
// @lc code=end

