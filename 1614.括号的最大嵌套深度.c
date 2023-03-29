/*
 * @lc app=leetcode.cn id=1614 lang=c
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start
#include <string.h>

int maxDepth(char * s){
    int max = 0;
    int len = strlen(s);
    int t = 0;
    for(int i=0;i<len;i++){
        if(s[i] == '('){
            t++;
            if(t > max)max = t;
        }
        else if(s[i] == ')'){
            t--;
        }
    }
    if(t == 0)return max;
    else return 0;
}
// @lc code=end

