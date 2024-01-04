/*
 * @lc app=leetcode.cn id=36 lang=c
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int *num1, *num2;
    num1 = (int*)malloc(sizeof(int)*10);
    num2 = (int*)malloc(sizeof(int)*10);
    for(int i=0; i< boardSize; i++){
        for(int x=0; x<10; x++){
            num1[x] = 0;
            num2[x] = 0;
        }
        for(int j=0; j<boardColSize[0]; j++){
            if (board[i][j] != '.'){
                num1[board[i][j]-'0']++;
                if (num1[board[i][j]-'0'] > 1)return false;
            }
            if (board[j][i] != '.'){
                num2[board[j][i]-'0']++;
                if (num2[board[j][i]-'0'] > 1)return false;
            }
        }
    }
    for(int i=0; i<boardSize;i+=3){
        for(int j=0;j<boardSize;j+=3){
            int num3[10];
            for(int x=0;x<10;x++)num3[x]=0;
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    char t = board[i+k][j+l];
                    if(t != '.'){
                        if(num3[t-'0'] == 1)return false;
                        else num3[t-'0']++;
                    }
                }
            }
        }
    }
    return true;
}
// @lc code=end

