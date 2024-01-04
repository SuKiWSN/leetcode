/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 */
#include <math.h>
#include <stdlib.h>
// @lc code=start
double recursion(double x, long n, long t, double res, double temp){
    if(2*t < n)return recursion(x, n, 2*t, res*temp, temp*temp);
    else{
        if(n == t)return res; 
        return recursion(x, n-t, 1, res * x, x);
    }
}
double myPow(double x, int n) {
    if(n == 0)return 1;
    long  N = n;
    N = n>0?N:-N;
    double res = recursion(x, N, 1, x, x);
    return n > 0 ? res : 1/res;
} 
// @lc code=end

