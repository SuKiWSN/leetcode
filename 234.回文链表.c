/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdbool.h>
typedef struct ListNode ListNode;

ListNode *reverse(ListNode *head){
    ListNode *front = head, *next = head->next, *tail = head;
    while(next){
        tail->next = next->next;
        next->next = front;
        front = next;
        next = tail->next;
    }
    return front;
}

bool isPalindrome(struct ListNode* head){
    int len = 0;
    ListNode *p = head;
    while(p){
        p = p->next;
        len++;
    }
    if(len == 1)return true;
    ListNode *q = head;
    for(int i=0;i<len/2;i++)q = q->next;
    if(len % 2 != 0)q = q->next;
    q = reverse(q);
    for(int i=0;i<len/2;i++){
        if(head->val != q->val)return false;
        head = head->next;
        q = q->next;
    }
    return true;
}
// @lc code=end

