/*
 * @lc app=leetcode.cn id=263 lang=c
 *
 * [263] 丑数
 */

// @lc code=start
#include <stdbool.h>
#include <stdio.h>

bool isUgly(int n){
    if(n == 0)return false;
    else if(n == 1)return true;
    while(n != 1){
        if(n % 2 == 0)n /= 2;
        else if(n % 3 == 0)n /= 3;
        else if(n % 5 == 0)n /= 5;
        else return false;
    }
    return true;
}
// @lc code=end

int main(){
    int n = 1;
    printf("%d\n", isUgly(n));
    return 0;
}