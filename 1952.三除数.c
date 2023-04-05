/*
 * @lc app=leetcode.cn id=1952 lang=c
 *
 * [1952] 三除数
 */

// @lc code=start
#include <stdbool.h>
#include <stdlib.h>

bool isThree(int n){
    int t = 0;
    for(int i=1;i<n;i++){
        if(i * (n/i) == n){
            if(i == n/i)t++;
            else t += 2;
            if(t > 3)return false;
        }
    }
    if(t == 3)return true;
    else return false;
}
// @lc code=end

