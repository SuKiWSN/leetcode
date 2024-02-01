/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 */
 struct ListNode {
    int val;
    struct ListNode *next;
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
    ListNode *hs = malloc(sizeof(ListNode));
    ListNode *hb = malloc(sizeof(ListNode));
    ListNode *p = hs, *q = hb, *t = head;
    p->next = q->next = NULL;
    while(head != NULL){
        head = head->next;
        if(t->val < x){
            p->next = t;
            t->next = NULL;
            p = t;
            t = head;
        }
        else{
            q->next = t;
            t->next = NULL;
            q = t;
            t = head;
        }
    }
    p->next = hb->next;
    return hs->next;
}
// @lc code=end

