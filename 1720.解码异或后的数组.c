/*
 * @lc app=leetcode.cn id=1720 lang=c
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    int *res = malloc(sizeof(int) * (encodedSize + 1));
    *returnSize = encodedSize + 1;
    res[0] = first;
    for(int i=1;i<encodedSize+1;i++){
        res[i] = res[i-1] ^ encoded[i-1];
    }
    return res;
}
// @lc code=end

