/*
 * @lc app=leetcode.cn id=1773 lang=c
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start


int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int res = 0;
    int type;
    if(!strcmp(ruleKey, "type"))type = 0;
    else if(!strcmp(ruleKey, "color"))type = 1;
    else type = 2;
    for(int i=0;i<itemsSize;i++){
        if(!strcmp(ruleValue, items[i][type]))res++;
    }
    return res;
}
// @lc code=end

