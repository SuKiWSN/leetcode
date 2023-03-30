/*
 * @lc app=leetcode.cn id=1796 lang=c
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start


int secondHighest(char * s){
    int max = 0;
    int res = 0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            if(s[i] > max){
                res = max;
                max = s[i];
            }
            else if(s[i] < max && s[i] > res){
                res = s[i];
            }
        }
    }
    return res - '0' >= 0?res-'0':-1;
}
// @lc code=end

