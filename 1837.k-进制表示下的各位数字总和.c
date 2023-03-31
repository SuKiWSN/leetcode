/*
 * @lc app=leetcode.cn id=1837 lang=c
 *
 * [1837] K 进制表示下的各位数字总和
 */

// @lc code=start
#include <stdio.h>

int sumBase(int n, int k){
    int res = 0;
    while(n){
        res += n % k;
        n /= k;
    }
    return res;

}
// @lc code=end

int main(){
    int n = 34;
    int k = 6;
    printf("%d\n", sumBase(n, k));
    return 0;
}