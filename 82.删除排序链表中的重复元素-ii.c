/*
 * @lc app=leetcode.cn id=82 lang=c
 *
 * [82] 删除排序链表中的重复元素 II
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *h = malloc(sizeof(ListNode));
    struct ListNode *p = head, *t = h;
    bool remove = false;
    h->next = head;
    if(p == NULL)return head;
    else{
        struct ListNode* q = p->next;
        while(p != NULL){
            while(q != NULL && q->val == p->val){
                p->next = q->next;
                q = q->next;
                remove = true;
            }
            p = q;
            if(remove ==true)h->next = p;
            else h = h->next;
            if(q!=NULL)q = q->next;
            remove = false;
        }
    }
    return t->next;
}
// @lc code=end

