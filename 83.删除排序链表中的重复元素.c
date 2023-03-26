/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
     int val;
     struct ListNode *next;
 };

void printl(struct ListNode* head){
    while(head){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");

}

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *h = (struct ListNode*)malloc(sizeof(struct ListNode));
    h->next = head;
    h->val = -999;
    while(h && h->next){
        if(h->val == h->next->val){
            h->next = h->next->next;
        }
        else
        h = h->next;
        // printl(head);
    }
    return head;
}
// @lc code=end


struct ListNode* create(int n){
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode)), *h;
    h = head;
    while(n--){
        int x;
        scanf("%d",&x);
        struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = x;
        h ->next = p;
        h = p;
    }
    return head->next;
}

int main(){
    struct ListNode *head;
    head = create(5);
    head = deleteDuplicates(head);
    return 0;
}
