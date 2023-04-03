/*
 * @lc app=leetcode.cn id=1869 lang=c
 *
 * [1869] 哪种连续子字符串更长
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkZeroOnes(char * s){
    int m1, m0, t1, t0;
    m1=m0=t1=t0=0;
    bool f = true;
    for(int i=0;i<strlen(s);i++){
        if(s[i] == '1'){
            if(f){
                t1++;
            }
            else{
                t1 = 1;
                f = true;
            }
            if(t1 > m1)m1 = t1;
        }
        else{
            if(!f){
                t0++;
            }
            else{
                t0 = 1;
                f = false;
            }
            if(t0 > m0)m0 = t0;
        }
    }
    return m1 > m0;
}
// @lc code=end

