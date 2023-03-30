/*
 * @lc app=leetcode.cn id=1768 lang=c
 *
 * [1768] 交替合并字符串
 */

// @lc code=start


char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1), len2 = strlen(word2);
    char *merge = malloc(len1+len2+1);
    merge[len1+len2] = '\0';
    int idx = 0;
    int i1 = 0, i2 = 0;
    while(idx < len1+len2){
        if(i1 < len1)merge[idx++] = word1[i1++];
        if(i2 < len2)merge[idx++] = word2[i2++];
    }
    return merge;
}
// @lc code=end

int main(){
    
}