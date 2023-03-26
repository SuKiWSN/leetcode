/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > a;
        return a;
    }
};
// @lc code=end

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int a[] = {7,2,3,4,5,6,7};
    sort(a, a+7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
