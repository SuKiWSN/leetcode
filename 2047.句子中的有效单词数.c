/*
 * @lc app=leetcode.cn id=2047 lang=c
 *
 * [2047] 句子中的有效单词数
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int countValidWords(char * sentence){
    int len = strlen(sentence);
    int res = 0;
    for(int i=0;i<len;i++){
        while(i<len&&sentence[i] == ' ')i++;
        if(i == len)break;
        int j = i;
        while(j<len&&sentence[j] != ' ')j++;
        int c1 = 0, c2 = 0;
        bool f = true;
        for(int k=i;k<j;k++){
            if(sentence[k] >= '0' && sentence[k] <= '9'){f = false; break;}
            if(sentence[k] == '-')c1++;
            else if(sentence[k] == '!' || sentence[k] == '.' || sentence[k] == ',')c2++;
            if(c1 > 1 || c2 > 1){f = false; break;}
            if((sentence[k] == '-' && k == i ) ||(sentence[k] == '-' && k == j-1) || (sentence[k] == '-' && (sentence[k-1] < 'a' || sentence[k-1] > 'z' || sentence[k+1] < 'a' || sentence[k+1] > 'z'))){f = false; break;}
            else if(c2 == 1 && sentence[j-1] != ',' && sentence[j-1] != '.' && sentence[j-1] != '!'){f = false; break;}
        }
        if(f)res++;
        i = j;
    }
    return res;
}
// @lc code=end

