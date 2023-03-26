/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    ListNode *p, *q, *p1, *q1;
    p = p1 = headA;
    q = q1 = headB;
    int l1 = 0, l2 = 0;
    while(p1){
        l1++;
        p1 = p1->next;
    }
    while(q1){
        l2++;
        q1 = q1->next;
    }
    if(l1 > l2){
        int i = l1-l2;
        while(i--)p = p->next;
    }
    else{
        int i = l2-l1;
        while(i--)q = q->next;
    }
    while(p){
        if(p == q)return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}
// @lc code=end

