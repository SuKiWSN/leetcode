/*
 * @lc app=leetcode.cn id=79 lang=c
 *
 * [79] 单词搜索
 */
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// @lc code=start
// void backtrack(char board[3][5], int boardSize, int* boardColSize, char* word, bool* exist, int pa){
void backtrack(char** board, int boardSize, int* boardColSize, char* word, bool* exist, int i, int j, int k, int pa){
    if(*exist == true)return;
    if(board[i][j] == word[pa]){
        if(++pa == strlen(word)){
            *exist = true;
            return;
        }                                                                                                                                                                                                                                         
        char t = board[i][j];
        board[i][j] = ' ';
        if(*exist==false&&j+1<*boardColSize&&board[i][j+1]!=' ')backtrack(board, boardSize, boardColSize, word, exist, i, j+1, k, pa);
        if(*exist==false && i+1<boardSize&&board[i+1][j]!=' ')backtrack(board, boardSize, boardColSize, word, exist, i+1, j, k,  pa);
        if(*exist==false&&j-1>=0&&board[i][j-1]!=' ')backtrack(board, boardSize, boardColSize, word, exist, i, j-1, k, pa);
        if(*exist==false&&i-1>=0&&board[i-1][j]!=' ')backtrack(board, boardSize, boardColSize, word, exist, i-1, j, k, pa);
        board[i][j] = t;
        pa--;
    }
    if(pa == 0){
        k++;
        if(k == boardSize * *boardColSize)return;
        i = k / *boardColSize;
        j = k % *boardColSize;
        backtrack(board, boardSize, boardColSize, word, exist, i, j, k, pa);
    }
}
// bool exist(char board[3][5], int boardSize, int* boardColSize, char* word) {
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    bool* exist = malloc(sizeof(bool));
    *exist = false;
    backtrack(board, boardSize, boardColSize, word, exist, 0, 0, 0, 0);
    return *exist;
}
// @lc code=end

int main(){
    char board[3][5] = {"ABCE", "SFCS", "ADEE"};
    int boardSize = 3; 
    int* boardColSize = malloc(sizeof(int));
    *boardColSize = 4;
    char word[7] = "ABCCED";
    bool e = exist(board, boardSize, boardColSize, word);
    printf("%d\n", e);
    return 0;
}