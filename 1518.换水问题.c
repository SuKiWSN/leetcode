/*
 * @lc app=leetcode.cn id=1518 lang=c
 *
 * [1518] 换水问题
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

int numWaterBottles(int numBottles, int numExchange){
    int res = numBottles;
    while(numBottles >= numExchange){
        res += numBottles / numExchange;
        numBottles = numBottles % numExchange + numBottles / numExchange;
    }
    return res;
}
// @lc code=end

int main(){
    int num = 15;
    int ex = 4;
    printf("%d\n", numWaterBottles(num, ex));
    return 0;
}