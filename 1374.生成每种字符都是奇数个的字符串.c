/*
 * @lc app=leetcode.cn id=1374 lang=c
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

// @lc code=start
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char * generateTheString(int n){
    char * res = malloc(n+1);
    res[n] = '\0';
    memset(res, 'a', n);
    if(n % 2 == 0)res[n-1] = 'b';
    return res;
    // char a = 'a';
    // int i = 0;
    // int t = n;
    // while(true){
    //     if(n % 2 == 0){
    //         if(n == 0)break;
    //         memset(res+i, a, 1);
    //         memset(res+i+1, a+1, t-i-1);
    //         break;
    //     }
    //     else{
    //         memset(res+i, a, 1);
    //         n--;
    //         i++;
    //         a++;
    //     }
    // }
    // return res;
}
// @lc code=end

int main(){
    int n = 7;
    char * res = generateTheString(n);
    printf("%s\n", res);
    return 0;

}