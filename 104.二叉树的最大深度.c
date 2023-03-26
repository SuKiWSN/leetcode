/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
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
#include <stdlib.h>
typedef struct TreeNode TreeNode;
void trackback(TreeNode *root, int* depth, int* max){
    if(root->left){
        (*depth)++;
        if(*depth > *max){
            *max = *depth;
        }
        trackback(root->left, depth, max);
    }
    if(root->right){
        (*depth)++;
        if(*depth > *max){
            *max = *depth;
        }
        trackback(root->right, depth, max);
    }
    (*depth)--;
}

int maxDepth(struct TreeNode* root){
    if(!root)return 0;
    int *depth = malloc(sizeof(int)), *max = malloc(sizeof(int));
    *depth = 1;
    *max = 1;
    trackback(root, depth, max);
    return *max;
    
}
// @lc code=end

