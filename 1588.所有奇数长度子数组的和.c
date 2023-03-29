/*
 * @lc app=leetcode.cn id=1588 lang=c
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start


int sumOddLengthSubarrays(int* arr, int arrSize){
    int res = 0;
    for(int i=1;i<=arrSize;i+=2){
        for(int j=0;j+i-1<arrSize;j++){
            for(int k=0;k<i;k++){
                res += arr[j+k];
            }
        }
    }
    return res;
}
// @lc code=end

