#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* e1,const void* e2) {
    return *(int*)e1 - *(int*)e2;
}

int main(){
    int arr[] = {3, 6, 2, 1, 4, 9, 8};
    qsort(arr, 7, sizeof(int), cmp);
    for(int i=0;i<7;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}