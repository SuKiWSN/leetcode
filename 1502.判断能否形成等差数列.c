/*
 * @lc app=leetcode.cn id=1502 lang=c
 *
 * [1502] 判断能否形成等差数列
 */

// @lc code=start
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), cmp);
    int d = arr[1] - arr[0];
    for(int i=1;i<arrSize;i++){
        if(arr[i] - arr[i-1] != d)return false;
    }
    return true;
}
// @lc code=end

