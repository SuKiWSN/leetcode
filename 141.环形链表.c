/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 快指针在循环链表中必然能追上慢指针

bool hasCycle(struct ListNode *head) {
    struct ListNode *p, *q;
    p = q = head;
    while(p&&q){
        p = p->next;
        if(!p || !q->next)return false;
        q = q->next->next;
        if((p == q) && q && p) return true;
        else if(p && q && q->next && (p == q->next))return true;
    }
    return false;
}
// @lc code=end

