/*
 * @lc app=leetcode.cn id=191 lang=c
 *
 * [191] 位1的个数
 */

// @lc code=start
int hammingWeight(uint32_t n) {
    short res = 0;
    while(n){
        if(n%2 == 1)res++;
        n >>= 1;
    }
    return res;
}
// @lc code=end

