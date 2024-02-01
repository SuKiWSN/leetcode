/*
 * @lc app=leetcode.cn id=120 lang=c
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int dp0[200] = {0};
    int dp1[200] = {0};
    for(int i=0;i<triangleSize;i++){
        for(int j=0;j<*(triangleColSize+i);j++){
            if(j==0)dp1[0] = dp0[0] + triangle[i][0];
            else if(j == *(triangleColSize+i)-1)dp1[j] = dp0[j-1] + triangle[i][j];
            else dp1[j] = dp0[j-1] < dp0[j] ? dp0[j-1]+triangle[i][j] : dp0[j] + triangle[i][j];
        }
        for(int i=0;i<200;i++)dp0[i] = dp1[i];
    }
    int min = 99999;
    for(int i=0;i<triangleSize;i++){
        if(dp0[i] < min)min = dp0[i];
    }
    return min;
}
// @lc code=end

