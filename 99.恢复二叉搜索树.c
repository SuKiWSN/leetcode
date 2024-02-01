/*
 * @lc app=leetcode.cn id=99 lang=c
 *
 * [99] 恢复二叉搜索树
 */
#include <stdlib.h>
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
typedef struct TreeNode TreeNode;
void nvisist(TreeNode *root, TreeNode** t, int *k, TreeNode **list){
    if(*k == 2)return;
    if(root->left!=NULL)nvisist(root->left, t, k, list);
    if(root->val < (*t)->val){
        (*k)++;
        if(*k == 1){
            list[0] = *t;
            list[1] = root;
        }
        else if(*k == 2){
            list[1] = root;
            return;
        }
    }
    *t = root;
    if(root->right!=NULL)nvisist(root->right, t, k, list);
}
void recoverTree(struct TreeNode* root) {
    TreeNode **list;
    list = malloc(sizeof(TreeNode*) * 2);
    TreeNode *t = malloc(sizeof(TreeNode));
    TreeNode **y = malloc(sizeof(TreeNode*));
    *y = t;
    t->val = INT32_MIN;
    int *k = malloc(sizeof(int));
    *k = 0;
    nvisist(root, y, k, list);
    int x = list[0]->val;
    list[0]->val = list[1]->val;
    list[1]->val = x;
}
// @lc code=end