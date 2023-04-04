/*
 * @lc app=leetcode.cn id=1925 lang=c
 *
 * [1925] 统计平方和三元组的数目
 */

// @lc code=start
#include <math.h>
#include <stdio.h>

// 判断开根号再平方后的数是否为原数
int countTriples(int n){
    int res = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(pow((int)sqrt(i*i + j*j), 2) == i*i+j*j && sqrt(i*i + j*j) <= n){
                res++;
            }
        }
    }
    return res;
}
// @lc code=end

