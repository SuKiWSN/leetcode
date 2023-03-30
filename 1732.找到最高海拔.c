/*
 * @lc app=leetcode.cn id=1732 lang=c
 *
 * [1732] 找到最高海拔
 */

// @lc code=start


int largestAltitude(int* gain, int gainSize){
    int res = 0;
    int max = 0;
    for(int i=0;i<gainSize;i++){
        res += gain[i];
        if(res > max)max = res;
    }
    return max;
}
// @lc code=end

