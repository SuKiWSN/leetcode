/*
 * @lc app=leetcode.cn id=1491 lang=c
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

double average(int* salary, int salarySize){
    qsort(salary, salarySize, sizeof(int), cmp);
    for(int i = 2; i < salarySize-1;i++){
        salary[i] += salary[i-1];
    }
    return (double)salary[salarySize-2] / (salarySize-2);
}
// @lc code=end
