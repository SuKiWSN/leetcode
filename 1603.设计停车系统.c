/*
 * @lc app=leetcode.cn id=1603 lang=c
 *
 * [1603] 设计停车系统
 */

// @lc code=start

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int big;
    int medium;
    int small;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *parkingsystem = malloc(sizeof(ParkingSystem));
    parkingsystem->big = big;
    parkingsystem->medium = medium;
    parkingsystem->small = small;
    return parkingsystem;

}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if(carType == 1){
        if(obj->big == 0)return false;
        obj->big--;
    }
    else if(carType == 2){
        if(obj->medium == 0)return false;
        obj->medium--;
    }
    else{
        if(obj->small == 0)return false;
        obj->small--;
    }
    return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/
// @lc code=end

