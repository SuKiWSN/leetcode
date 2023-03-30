/*
 * @lc app=leetcode.cn id=1725 lang=c
 *
 * [1725] 可以形成最大正方形的矩形数目
 */

// @lc code=start


int countGoodRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize){
    int max = 0;
    int res = 0;
    for(int i=0;i<rectanglesSize;i++){
        int t = rectangles[i][0] < rectangles[i][1]?rectangles[i][0] : rectangles[i][1];
        if(t > max){
            max = t;
            res = 1;
        }
        else if (t==max)res++;
    }
    return res;
}
// @lc code=end

