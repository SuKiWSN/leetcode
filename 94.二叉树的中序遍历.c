/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

//  struct TreeNode {
//      int val;
//      struct TreeNode *left;
//      struct TreeNode *right;
//  };
 


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode TreeNode;
void inorder(TreeNode* root, int* ans, int* returnSize){
    if(root->left)inorder(root->left, ans, returnSize);
    ans[(*returnSize)++] = root->val;
    if(root->right)inorder(root->right, ans, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int* ans = malloc(sizeof(int) * 100);
    if(!root)return ans;
    inorder(root, ans, returnSize);
    for(int i=0;i<3; i++){
        printf("%d\n", ans[i]);
    }
    return ans;
}
// @lc code=end

int main(){

    return 0;
}