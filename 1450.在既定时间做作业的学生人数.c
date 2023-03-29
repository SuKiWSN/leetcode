/*
 * @lc app=leetcode.cn id=1450 lang=c
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start


int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime){
    int res = 0;
    for(int i=0;i<startTimeSize;i++){
        if(startTime[i] <= queryTime && endTime[i] >= queryTime)res++;
    }
    return res;
}
// @lc code=end

