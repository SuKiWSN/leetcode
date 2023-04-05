/*
 * @lc app=leetcode.cn id=2037 lang=c
 *
 * [2037] 使每位学生都有座位的最少移动次数
 */

// @lc code=start
#include <stdlib.h>
int cmp(const void *a, const void *b){
    return *(int*)a- *(int*)b;
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize){
    int res = 0;
    qsort(seats, seatsSize, sizeof(int), cmp);
    qsort(students, studentsSize, sizeof(int), cmp);
    for(int i=0;i<seatsSize;i++){
        res += abs(seats[i] - students[i]);
    }
    return res;
}
// @lc code=end