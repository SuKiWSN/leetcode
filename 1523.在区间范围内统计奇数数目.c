/*
 * @lc app=leetcode.cn id=1523 lang=c
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lc code=start
#include <stdio.h>

int countOdds(int low, int high){
    if(low % 2 == 0 && high % 2 == 0){
        return (high - low) / 2;
    }
    else{
        return (high - low) / 2 + 1;
    }
}
// @lc code=end

int main(){
    int l = 7, h = 10;
    printf("%d\n", countOdds(l, h));
    return 0;
}