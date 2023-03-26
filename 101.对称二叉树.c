/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>
typedef struct TreeNode TreeNode;

bool is(TreeNode* p, TreeNode* q){
    if(!p && !q)return true;
    else if(p && !q)return false;
    else if(!p && q)return false;
    else if(p->val != q->val)return false;
    else return is(p->left, q->right) && is(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
    return is(root->left, root->right);
}
// @lc code=end