/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode{
//     int val;
//     struct ListNode *next;
// };
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL)return NULL;
    struct ListNode* rail = head;
    int len = 1;
    while(rail->next != NULL){
        len++;
        rail = rail->next;
    }
    k %= len;
    if(k == 0 || head->next == NULL)return head;
    struct ListNode* h = head;
    for(int i=0;i<len-k-1;i++)h = h->next;
    struct ListNode* newHead = h->next;
    h->next = NULL;
    rail->next = head;
    return newHead;
}
// @lc code=end

