/*
 * @lc app=leetcode.cn id=1629 lang=c
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start


char slowestKey(int* releaseTimes, int releaseTimesSize, char * keysPressed){
    int word[26] = {0};
    word[keysPressed[0] - 'a'] = releaseTimes[0];
    int max = releaseTimes[0];
    for(int i=1;i<releaseTimesSize;i++){
        if(releaseTimes[i] - releaseTimes[i-1] > word[keysPressed[i] - 'a']){
            if(releaseTimes[i] - releaseTimes[i-1] > max){
                max = releaseTimes[i] - releaseTimes[i-1];
            }
            word[keysPressed[i] - 'a'] = releaseTimes[i] - releaseTimes[i-1];
        }
    }
    for(int i=25;i>=0;i--){
        if(word[i] == max)return i + 'a';
    }
    return 'a';
}
// @lc code=end

