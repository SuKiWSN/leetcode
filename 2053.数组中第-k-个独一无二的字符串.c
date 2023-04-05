/*
 * @lc app=leetcode.cn id=2053 lang=c
 *
 * [2053] 数组中第 K 个独一无二的字符串
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

char * kthDistinct(char ** arr, int arrSize, int k){
    int cnt = 0;
    for(int i=0;i<arrSize;i++){
        bool f = true;
        for(int j=0;j<arrSize;j++){
            if(!strcmp(arr[i], arr[j])){
                if(i != j){
                    f = false;
                    break;
                }
            }
        }
        if(f)cnt++;
        if(cnt == k)return arr[i];
    }
    return "";
}
// @lc code=end

