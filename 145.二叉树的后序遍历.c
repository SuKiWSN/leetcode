/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode TreeNode;

void postorder(TreeNode* root, int* ans, int* cnt){
    if(!root) return;
    postorder(root->left, ans, cnt);
    postorder(root->right, ans, cnt);
    ans[(*cnt)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *ans = malloc(sizeof(int) * 100);
    postorder(root, ans, returnSize);
    return ans;
}
// @lc code=end

