/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int min = 1e9;
    int max = 0;
    int ans = 0;
    for(int i=0;i<pricesSize;i++){
        if(prices[i] < min){
            min = prices[i];
            max = 0;
        }
        if(prices[i] > max){
            max = prices[i];
            if(max - min > ans) ans = max-min;
        }
    }
    return ans;
}
// @lc code=end

int main(){
    return 0;
}