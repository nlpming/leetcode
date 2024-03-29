//
// Created by 陈志明 on 2021/8/22.
//

/*
 * 考点：滑动窗口指针、哈希表、字符串；
 * 难度：***
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int left = -1, right = 0, max_len = 0;
        unordered_set<char> record;
        record.insert(s[0]);

        //注意：
        // 1. record用于记录(left, right]中的元素；
        // 2. 循环终止条件为：left <= right，此时record为空；
        // 3. unordered_set中插入元素insert，删除元素erase；
        // 4. unordered_set查找一个元素是否存在cout，如果存在返回1；否则返回0；

        //NOTE: 注意此处终止条件；left == right表示滑动窗口中元素为空；
        while(left <= right){
            if(right+1 < s.length() && !record.count(s[right+1])){
                right++;
                record.insert(s[right]);
            }else{
                if(right-left > max_len){
                    max_len = right-left;
                }

                left++;
                record.erase(s[left]);
            }
        }

        return max_len;
    }
};