/*
 * @lc app=leetcode.cn id=1346 lang=c
 *
 * [1346] 检查整数及其两倍数是否存在
 */

// @lc code=start

// 思路: 快排+双指针,时间复杂度O(nlogn) https://leetcode.cn/problems/check-if-n-and-its-double-exist/solutions/101742/jian-cha-zheng-shu-ji-qi-liang-bei-shu-shi-fou-cun/
#include <stdio.h>
#include <stdbool.h>

void fastsort(int* arr, int s, int e){
    int i = s, j = e;
    bool f = true;
    while(s < e){
        if(arr[s] > arr[e]){
            int t = arr[s];
            arr[s] = arr[e];
            arr[e] = t;
            f = !f;
        }
        if(f)s++;
        else e--;
    }
    if(i != s)fastsort(arr, i, s-1);
    if(j != s)fastsort(arr, s+1, j);
}

bool checkIfExist(int* arr, int arrSize){
    fastsort(arr, 0, arrSize-1);
    int p = 0, q, x, y;
    while(p < arrSize && arr[p] < 0)p++;
    x = p-1;
    y = p-2;
    q = p+1;
    while(q<arrSize){
        while(q<arrSize && arr[q] < arr[p] * 2)q++;
        if(q < arrSize && arr[q] == arr[p]*2)return true;
        p++;
    }
    if(q < arrSize && arr[q] == arr[p] * 2)return true;
    while(y >=0){
        while(y>=0 && arr[y] > arr[x] * 2)y--;
        if(y >=0 && arr[y] == arr[x] * 2)return true;
        x--;
    }
    if(y >= 0 && arr[y] == arr[x] * 2)return true;
    return false;
}
// @lc code=end

int main(){
    int arr[88] = {-95,-299,357,715,-438,-759,255,418,-647,-805,-546,-182,-523,13,-79,-227,537,-655,993,-526,-518,679,-420,-53,120,187,-203,-567,-75,464,-472,-324,16,215,-773,862,-563,-839,-906,-969,633,-990,756,-17,-346,820,-216,736,188,-412,881,-599,-181,-673,802,688,553,323,-689,625,871,-938,-969,-207,-703,794,361,111,-884,156,-223,-480,-734,-838,-53,335,720,-379,855,-971,-928,99,-876,75,721,-736,-913,911};
    bool res = checkIfExist(arr, 88);
    printf("%d\n", res);
    return 0;
}