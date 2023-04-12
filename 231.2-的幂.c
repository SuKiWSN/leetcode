/*
 * @lc app=leetcode.cn id=231 lang=c
 *
 * [231] 2 的幂
 */

// @lc code=start
#include <stdbool.h>

bool isPowerOfTwo(int n){
    for(int i=0;i<31;i++){
        if(1<<i == n)return true;
    }
    return false;
}
// @lc code=end