/*
 * @lc app=leetcode.cn id=168 lang=c
 *
 * [168] Excel表列名称
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

// 本题需要我们将从 1 开始，因此在执行「进制转换」操作前，我们需要先对 columnNumber 执行减一操作，从而实现整体偏移。

char * convertToTitle(int columnNumber){
    char* ans = malloc(sizeof(char) * 8);
    ans[7] = '\0';
    int cnt = 6;
    while(columnNumber){
        columnNumber -= 1;
        ans[cnt--] = 'A' + columnNumber % 26;
        columnNumber /= 26;
    }
    return ans+cnt+1;
}
// @lc code=end

int main(){
    int n = 2147483647;
    char *ans = convertToTitle(n);
    printf("%s\n", ans);
    printf("%d\n", 701%26);
    return 0;
}