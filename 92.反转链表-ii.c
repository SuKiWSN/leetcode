/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 */
#include <stdlib.h>
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
typedef struct ListNode ListNode;
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(head->next == NULL)return head;
    ListNode *p1 = malloc(sizeof(ListNode));
    p1->next = head;
    ListNode *p = head, *q, *r;
    for(int i=1;i<left;i++){
        p1 = p1->next;
        p = p->next;
    }
    q = p->next;
    r = p;
    int t = right - left;
    while(t--){
        r->next = q->next;
        q->next = p;
        p = q;
        q = r->next;
    }
    p1->next = p;
    return left == 1 ? p : head;
}
// @lc code=end

