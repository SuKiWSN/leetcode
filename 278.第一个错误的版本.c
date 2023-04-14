/*
 * @lc app=leetcode.cn id=278 lang=c
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    unsigned long long s = 1;
    unsigned long long e = n;
    while(s<=e){
        if(isBadVersion((s+e)/2)){
            e = (s+e)/2-1;
        }
        else s = (s+e)/2+1;
    }
    return s;
}
// @lc code=end

