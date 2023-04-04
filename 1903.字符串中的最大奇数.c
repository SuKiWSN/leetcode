/*
 * @lc app=leetcode.cn id=1903 lang=c
 *
 * [1903] 字符串中的最大奇数
 */

// @lc code=start
#include <string.h>
// 从后往前只要有一位是奇数从头到这一位就是最大奇数

char * largestOddNumber(char * num){
    int len = strlen(num);
    for(int i=len-1;i>=0;i--){
        if(num[i] % 2){
            num[i+1] = '\0';
            return num;
        }
    }
    return "";
}
// @lc code=end

