/*
 * @lc app=leetcode.cn id=1700 lang=c
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start


int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){
    int num1 = 0, num0 = 0;
    for(int i=0;i<studentsSize;i++){
        if(students[i] == 0)num0++;
        else num1++;
    }
    for(int i=0;i<studentsSize;i++){
        if(sandwiches[i] == 0){
            if(num0 > 0){
                num0--;
            }
            else return num0 + num1;
        }
        else{
            if(num1 > 0){
                num1--;
            }
            else return num1 + num0;
        }
    }
    return 0;
}
// @lc code=end

