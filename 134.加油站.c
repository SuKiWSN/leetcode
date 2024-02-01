/*
 * @lc app=leetcode.cn id=134 lang=c
 *
 * [134] 加油站
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int remind = 0, passed = 0, s = 0, e = 0;
    while(s < gasSize && passed != costSize){
        if(remind + gas[e%gasSize] - cost[e%gasSize] >= 0){
            remind += gas[e%gasSize] - cost[e%gasSize];
            passed++;
            e++;
        }
        else if(e != s){
            s = e;
            passed = 0;
            remind = 0;
        }
        else if(e == s){
            s++;
            e++;
        }
    }
    if(passed == gasSize)return s%gasSize;
    else return -1;
}
// @lc code=end

int main(){
    int gas[5] = {3, 3, 4};
    int cost[5] = {3, 4, 4};
    int* ga = malloc(sizeof(int)*5);
    int* cos = malloc(sizeof(int)*5);
    for(int i=0;i<5;i++){
        ga[i] = gas[i];
        cos[i] = cost[i];
    }
    int i = canCompleteCircuit(ga, 3, cos, 3);
    printf("%d\n", i);
    return 0;
}