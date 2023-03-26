/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start

//  * Definition for a binary tree node.
//  struct TreeNode {
//      int val;
//      struct TreeNode *left;
//      struct TreeNode *right;
//  };
 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
typedef struct TreeNode TreeNode;

void preorder(TreeNode* root, int* ans, int *cnt){
    if(!root) return;
    ans[(*cnt)++] = root->val;
    preorder(root->left, ans, cnt);
    preorder(root->right, ans, cnt);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    // returnSize = malloc(sizeof(int));
    *returnSize = 0;
    int *ans = malloc(sizeof(int)*100);
    preorder(root, ans, returnSize);
    for(int i=0;i<*returnSize;i++){
        printf("%d\n", ans[i]);
    }
    printf("%d\n", *returnSize);
    return ans;
}
// @lc code=end

int main(){
    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
    root->val = 1;
    root->left = NULL;
    TreeNode *p = (TreeNode*) malloc(sizeof(TreeNode));
    p->val = 2;
    root->right = p;
    TreeNode *q = (TreeNode*) malloc(sizeof(TreeNode));
    q->val = 3;
    q->left = NULL;
    q->right = NULL;
    p->left = q;
    p->right = NULL;
    int *ans;
    int *returnSize;
    ans = preorderTraversal(root, returnSize);
    // printf("%d\n", *returnSize);
    // for(int i=0;i<*returnSize;i++){
    //     printf("%d\n", ans[i]);
    // }
    return 0;
}
