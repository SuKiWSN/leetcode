/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
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

// 反转链表代码记住
typedef struct ListNode ListNode;

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)return head;
    ListNode *p = head, *q = head->next, *r = head;
    while(q){
        r->next = q->next;
        q->next = p;
        p = q;
        q = r->next;
    }
    return p;
}
// @lc code=end

