/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void nvisist(struct TreeNode *root, bool* res, long* t){
    if(root->left!=NULL)nvisist(root->left, res, t);
    if(root->val <= *t){
        *res = false;
        return;
    }
    else *t = root->val;
    if(root->right!=NULL)nvisist(root->right, res, t);
}
bool isValidBST(struct TreeNode* root) {
    bool *res = malloc(sizeof(bool));
    *res = true;
    long* t = malloc(sizeof(long));
    *t = INT64_MIN;
    nvisist(root, res, t);
    return *res;
}
// @lc code=end

int main(){
    TreeNode *root = malloc(sizeof(TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = 0;
    bool res = isValidBST(root);
    printf("%d\n", res);
    return 0;
}