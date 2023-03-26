/*
 * @lc app=leetcode.cn id=1323 lang=c
 *
 * [1323] 6 和 9 组成的最大数字
 */

// @lc code=start

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximum69Number (int num){
    int a[5] = {0};
    int n = num;
    int i = 0;
    while(n){
        a[4-i] = n%10;
        i++;
        n /= 10;
    }
    int res = 0;
    for(int j=4-i;j<5;j++){
        if(a[j] == 6){
            a[j] = 9;
            break;
        }
    }
    for(int j=4-i;j<5;j++){
        res*=10;
        res += a[j];
    }
    return res;
}
// @lc code=end

int main(){
    int n = 669;
    printf("%d\n", maximum69Number(n));
    return 0;
}