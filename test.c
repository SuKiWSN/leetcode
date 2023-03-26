#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p = malloc(sizeof(int)*1);
    int *q = malloc(sizeof(int)*2);
    *p = 10;
    *(q+1) = 9;
    *q = 2;
    int **ans = malloc(sizeof(int*)*2);
    *ans = p;
    *(ans+1) = q;
    printf("%d\n", *(*(ans+3)));
}