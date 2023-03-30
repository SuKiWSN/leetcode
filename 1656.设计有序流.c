/*
 * @lc app=leetcode.cn id=1656 lang=c
 *
 * [1656] 设计有序流
 */

// @lc code=start


#include <stdlib.h>
typedef struct {
    int ptr;
    int streamSize;
    char** value;
} OrderedStream;


OrderedStream* orderedStreamCreate(int n) {
    OrderedStream *obj = malloc(sizeof(OrderedStream));
    obj->ptr = 0;
    obj->value = malloc(sizeof(char*)*n);
    obj->streamSize = n;
    for(int i=0;i<n;i++){
        obj->value[i] = malloc(sizeof(char)* 6);
    }
    return obj;
}

char ** orderedStreamInsert(OrderedStream* obj, int idKey, char * value, int* retSize) {
    obj->
}

void orderedStreamFree(OrderedStream* obj) {
    
}

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char ** param_1 = orderedStreamInsert(obj, idKey, value, retSize);
 
 * orderedStreamFree(obj);
*/
// @lc code=end

