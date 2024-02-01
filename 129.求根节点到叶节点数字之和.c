/*
 * @lc app=leetcode.cn id=129 lang=c
 *
 * [129] 求根节点到叶节点数字之和
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#include <stdlib.h>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
void backtrack(TreeNode* root, int temp, int* res){
    if(root->left == NULL && root->right == NULL){
        temp *= 10;
        temp += root->val;
        *res += temp;
        return;
    }
    if(root->left != NULL)backtrack(root->left, temp*10+root->val, res);
    if(root->right != NULL)backtrack(root->right, temp*10+root->val, res);
}
int sumNumbers(struct TreeNode* root) {
    int* res = malloc(sizeof(int));
    *res = 0;
    backtrack(root, 0, res);
    return *res;
}
// @lc code=end

