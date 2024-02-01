/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
 */
struct TreeNode {
   int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct TreeNode TreeNode;
void visist(TreeNode *root, int *returnSize, int* returnColumnSizes, TreeNode** list, int idx, int n, int level){
    if(idx == n)return;
    
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
}
// @lc code=end

