/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
 */

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
struct ListNode* removeElements(struct ListNode* head, int val){
    ListNode* h = (ListNode*)malloc(sizeof(ListNode));
    h->next = head;
    ListNode *p = head, *q = h;

    while(p){
        if(p->val == val)q->next = p->next;
        else q = q->next;
        p = p->next;
    }
    return h->next;
}
// @lc code=end

