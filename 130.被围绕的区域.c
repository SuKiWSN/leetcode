/*
 * @lc app=leetcode.cn id=130 lang=c
 *
 * [130] 被围绕的区域
 */
#include <stdbool.h>
// @lc code=start
void recursion(char** board, int boardSize, int* boardColSize, int i, int j){
    board[i][j] = 'S';
    if(i-1>=0 && board[i-1][j]=='O')recursion(board, boardSize, boardColSize, i-1, j);
    if(i+1<boardSize && board[i+1][j]=='O')recursion(board, boardSize, boardColSize, i+1, j);
    if(j-1>=0 && board[i][j-1]=='O')recursion(board, boardSize, boardColSize, i, j-1);
    if(j+1<*boardColSize && board[i][j+1]=='O')recursion(board, boardSize, boardColSize, i, j+1);
}
void solve(char** board, int boardSize, int* boardColSize) {
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<*boardColSize;j++){
            if(board[i][j] == 'O'){
                if(i==0 || i == boardSize-1 || j==0 || j == (*boardColSize)-1){
                    recursion(board, boardSize, boardColSize, i, j);
                }
            }
        }
    }
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<*boardColSize;j++){
            if(board[i][j] == 'S')board[i][j] = 'O';
            else if(board[i][j] == 'O')board[i][j] = 'X';
        }
    }
}
// @lc code=end

