/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
bool isAnagram(char * s, char * t){
    int arr[26] = {0};
    if(strlen(s) != strlen(t))return false;
    for(int i=0;i<strlen(s);i++){
        arr[s[i]-'a']++;
    }
    for(int i=0;i<strlen(t);i++){
        arr[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(arr[i] != 0)return false;
    }
    return true;
}
// @lc code=end

