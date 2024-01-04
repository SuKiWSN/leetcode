/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 */
#include <stdio.h>
// @lc code=start
int uniquePaths(int m, int n) {
    int s = n; //3
    int e = 1; //1
    long long res = 1;
    for(int i=0;i<m-1;i++){
        res *= s++;
        res /= e++;
    }
    return res;
    }
// @lc code=end

int main(){
    int m = 59, n = 5;
    int res = uniquePaths(m, n);
    printf("%d\n", res);
}