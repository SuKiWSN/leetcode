/*
 * @lc app=leetcode.cn id=1556 lang=c
 *
 * [1556] 千位分隔数
 */

// @lc code=start

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * thousandSeparator(int n){
    char *res = malloc(sizeof(char) * 31);
    memset(res, '\0', sizeof(char) * 31);
    if(n == 0)return "0";
    int idx = 29, t = 0;
    while(n){
        res[idx--] = '0' + n % 10;
        t++;
        n /= 10;
        if(t % 3 == 0 && n)res[idx--] = '.';
    }
    return res+idx+1;
}
// @lc code=end

int main(){
    int n = 1234;
    printf("%s\n", thousandSeparator(n));
    return 0;
}