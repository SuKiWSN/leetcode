/*
 * @lc app=leetcode.cn id=108 lang=c
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start

//  * Definition for a binary tree node.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

typedef struct TreeNode TreeNode;
void create(TreeNode *h, int s, int e, int* nums){
    if(s > e)return;
    int mid = (s+e+1)/2;
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    p->val = nums[mid];
    p->left = NULL;
    p->right = NULL;
    if(p->val > h->val)h->right = p;
    else h->left = p;
    if(mid != s)create(p, s, mid-1, nums);
    if(mid != e)create(p, mid+1, e, nums);
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    int s = 0;
    int e = numsSize-1;
    TreeNode *head = (TreeNode*)malloc(sizeof(TreeNode));
    head->val = nums[(e+s+1)/2];
    head->left = NULL;
    head->right = NULL;
    create(head, 0, (e+s+1)/2-1, nums);
    create(head, (e+s+1)/2+1, e, nums);
    return head;
}
// @lc code=end

int main(){
    int nums[5] = {1, 3};
    int numsSize = 2;
    TreeNode* head = sortedArrayToBST(nums, numsSize);

}