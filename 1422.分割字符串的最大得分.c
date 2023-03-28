/*
 * @lc app=leetcode.cn id=1422 lang=c
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
#include <stdio.h>
#include <string.h>

int maxScore(char * s){
    int len = strlen(s);
    int score = 0;
    for(int i=1;i<len;i++){
        if(s[i] == '1')score++;
    }
    score += (s[0] == '0'?1:0);
    int max = score;
    for(int i=1;i<len-1;i++){
        if(s[i] == '1')score = score-1;
        else {
            score = score+1;
            if(score > max)max = score;
        }
    }
    return max;
}
// @lc code=end

