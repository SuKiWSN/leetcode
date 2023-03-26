#include <stdio.h>
#include <stdlib.h>
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

int main(){
    int arr[1000] = {-363,-530,423,738,-892,22,-878,605,-985,-838,216,-52,-995,999,610,305,-498,-729,457,-198,648,504,263,955,-205,-545,215,745,729,264,-434,-625,480,-554,-670,-815,813,848,879,-324,-290,-824,-751,909,644,833,139,-528,-581,-328,628,147,98,-83,623,589,445,-831,-117,170,-271,931,828,-662,-630,265,-792,-275,758,-622,407,790,895,10,250,-838,-66,-117,-553,-871,-862,363,298,-485,-328,-198,719,-246,191,-332,-119,58,271,226,333,-856,-611,829,-157,-289,78,509,18,-291};
    int arrSize = 104;
    fastsort(arr, 0, 87);
    for(int i=0;i<arrSize;i++)printf("%d\n",arr[i]);
    for(int i=0;i<arrSize;i++){
        for(int j=i;j<arrSize;j++){
            if(arr[i]*2 == arr[j] || arr[i] == arr[j] * 2){
                printf("%d %d\n", arr[i], arr[j]);
                break;
            }

        }
    }
}