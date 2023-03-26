/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
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
#include <stdlib.h>
typedef struct TreeNode TreeNode;

void computedeep(TreeNode *root, int* deep, int* max){
    if(root->left){
        (*deep)++;
        if(*max < *deep) *max = *deep;
        computedeep(root->left, deep, max);
    }
    if(root->right){
        (*deep)++;
        if(*max < *deep) *max = *deep;
        computedeep(root->right, deep, max);
    }
    *deep--;
}

bool firstvisit(TreeNode *root){
    int *deepl = (int*)malloc(sizeof(int));
    int *deepr = (int*)malloc(sizeof(int));
    int *maxl = (int*)malloc(sizeof(int));
    int *maxr = (int*)malloc(sizeof(int));
    *deepl = 1;
    *deepr = 1;
    *maxl = 1;
    *maxr = 1;
    if(root){
        computedeep(root->left, deepl, maxl);
        computedeep(root->right, deepr, maxr);
        if(abs(*maxl-*maxr) > 1)return false;
        else return firstvisit(root->left) && firstvisit(root->right);
    }
    else return true;
}

bool isBalanced(struct TreeNode* root){
    firstvisit(root);
}
// @lc code=end

