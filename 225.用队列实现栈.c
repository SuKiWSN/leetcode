/*
 * @lc app=leetcode.cn id=225 lang=c
 *
 * [225] 用队列实现栈
 */

// @lc code=start



typedef struct {
    int arr[100];
    int top;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));
    stack->top = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->top++;
    obj->arr[obj->top] = x;
}

int myStackPop(MyStack* obj) {
    obj->top--;
    return obj->arr[obj->top+1];
}

int myStackTop(MyStack* obj) {
    return obj->arr[obj->top];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->top == -1)return true;
    else return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
// @lc code=end

