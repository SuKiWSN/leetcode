/*
 * @lc app=leetcode.cn id=202 lang=c
 *
 * [202] 快乐数
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
// @lc code=start

int getnext(int n){
    int res = 0;
    while(n){
        res += (n%10)*(n%10);
        n /= 10;
    }
    return res;
}
bool isHappy(int n){
    int slower, faster;
    faster = getnext(getnext(n));
    slower = n;
    while(faster != 1 && faster != slower){
        slower = getnext(slower);
        faster = getnext(getnext(faster));
    }
    if(faster == 1)return true;
    else return false;
}
// @lc code=end

int main(){
    int n = 19;
    n = isHappy(n);
    printf("%d\n", n);
}