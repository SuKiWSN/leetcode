/*
 * @lc app=leetcode.cn id=190 lang=c
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    if(n==0 || n == UINT32_MAX)return n;
    unsigned long t = n;
    int cnt = 0;
    while(t < UINT32_MAX){
        t *= 2;
        cnt++;
    }
    uint32_t res = 0;
    while(n){
        res <<= 1;
        res += n%2;
        n /= 2;
    }
    res <<= (cnt-1>0?cnt-1:0);
    return res;
}
// @lc code=end

int main(){
    uint32_t n = 4294967293;
    printf("%lld\n", reverseBits(n));
    return 0;
}
