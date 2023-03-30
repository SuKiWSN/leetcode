/*
 * @lc app=leetcode.cn id=1704 lang=c
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start


bool halvesAreAlike(char * s){
    int a = 0, b = 0;
    for(int i=0;i<strlen(s)/2;i++){
        if(s[i] == 'a'||s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            a++;
        }
    }
    for(int i=strlen(s)/2;i<strlen(s);i++){
        if(s[i] == 'a'||s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            b++;
        }
    }
    if(a == b)return true;
    else return false;
}
// @lc code=end

