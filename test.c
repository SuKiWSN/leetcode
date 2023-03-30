#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* e1,const void* e2) {
    return *(int*)e1 - *(int*)e2;
}

int main(){
    printf("%d %d\n", 'a', 'A');
}