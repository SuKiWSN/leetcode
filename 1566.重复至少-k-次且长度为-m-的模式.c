/*
 * @lc app=leetcode.cn id=1566 lang=c
 *
 * [1566] 重复至少 K 次且长度为 M 的模式
 */

// @lc code=start
bool containsPattern(int* arr, int arrSize, int m, int k){
    int cnt = 0;
    for(int i=0;i<arrSize;i++){
        cnt = 1;
        for(int j=i;j+m*2-1<arrSize;j+=m){
            bool f = true;
            for(int l=j;l<j+m;l++){
                if(arr[l] != arr[l+m]){
                    f = false;
                    break;
                }
            }
            if(f)cnt++;
            else cnt--;
            if(cnt >= k)break;
        }
        if(cnt >= k)return true;
    }
    return false;
}
// @lc code=end

