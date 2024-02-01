/*
 * @lc app=leetcode.cn id=97 lang=c
 *
 * [97] 交错字符串
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
void backtrack(char* s1, char* s2, char* s3, int i1, int i2, int i3, bool* res){
    int l1 = strlen(s1), l2 = strlen(s2), l3 = strlen(s3);
    if(*res == true)return;
    if(i3 == l3){
        *res = true;
        return;
    }
    if(s1[i1] == s3[i3])backtrack(s1, s2, s3, i1+1, i2, i3+1, res);
    if(s2[i2] == s3[i3])backtrack(s1, s2, s3, i1, i2+1, i3+1, res);
}
bool isInterleave(char* s1, char* s2, char* s3) {
    if(strlen(s1) + strlen(s2) != strlen(s3))return false;
    bool* res = malloc(sizeof(bool));
    *res = false;
    backtrack(s1, s2, s3, 0, 0, 0, res);
    return *res;
}
// @lc code=end

int main(){
    char *s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
    *s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", 
    *s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    printf("%d\n", isInterleave(s1, s2, s3));
    return 0;
}