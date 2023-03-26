/*
 * @lc app=leetcode.cn id=171 lang=c
 *
 * [171] Excel 表列序号
 */

// @lc code=start


int titleToNumber(char * columnTitle){
    int ans = 0;
    while(*(columnTitle++) != '\0'){
        ans *= 26;
        ans += *(columnTitle-1) - 'A' + 1; // 每次需要先加一个偏移量 1
    }
    return ans;
}
// @lc code=end

