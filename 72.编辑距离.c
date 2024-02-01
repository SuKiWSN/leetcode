/*
 * @lc app=leetcode.cn id=72 lang=c
 *
 * [72] 编辑距离
 */
#include <string.h>
#include <stdio.h>
// @lc code=start
int minDistance(char* word1, char* word2) {
    int l1 = strlen(word1), l2 = strlen(word2), fp[l1+1][l2+1];
    for(int i=0;i<=l1;i++)fp[i][0] = i;
    for(int j=0;j<=l2;j++)fp[0][j] = j;
    int i=0, j=0;
    for(i=1;i<=l1; i++){
        for(j=1;j<=l2;j++){
            if(word1[i-1] == word2[j-1])fp[i][j] = fp[i-1][j-1];
            else{
                int min = fp[i-1][j-1] < fp[i-1][j] ? fp[i-1][j-1] : fp[i-1][j];
                fp[i][j] = (min < fp[i][j-1] ? min : fp[i][j-1]) + 1;
            }
        }
    }
    return fp[l1][l2];
}
// @lc code=end

int main(){
    char* w1 = "horse";
    char* w2 = "ros";
    int min = minDistance(w1, w2);
    printf("%d\n",min);
    return 0;
}