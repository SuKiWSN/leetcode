/*
 * @lc app=leetcode.cn id=1528 lang=c
 *
 * [1528] 重新排列字符串
 */

// @lc code=start
void fastsort(int * indices, char * s, int start, int end){
    int i = start, j = end;
    bool f = true;
    while(start < end){
        if(indices[start] > indices[end]){
            int t = indices[start];
            indices[start] = indices[end];
            indices[end] = t;
            f = !f;
            char t1 = s[start];
            s[start] = s[end];
            s[end] = t1;
        }
        if(f)start++;
        else end--;
    }
    if(i != start)fastsort(indices, s, i, start-1);
    if(j != start)fastsort(indices, s, start+1, j);
}
char * restoreString(char * s, int* indices, int indicesSize){
    fastsort(indices, s, 0, indicesSize-1);
    return s;
}
// @lc code=end

