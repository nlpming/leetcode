//
// Created by 陈志明 on 2020/5/14.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "print.h"

using namespace std;

/**
 * 题目描述：字母异位词分组
 * 考点：哈希表
 * 是否做出：是
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> record;
        vector<vector<string>> res;

        // 对字符串进行排序，作为key
        for(int i=0; i<strs.size(); i++){
            string s(strs[i].begin(), strs[i].end());
            sort(s.begin(), s.end());
            record[s].push_back(strs[i]);
        }

        // 构造输出
        for(unordered_map<string, vector<string>>::iterator it=record.begin(); it != record.end(); ++it){
            res.push_back(it->second);
        }
        return res;
    }
};

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = Solution().groupAnagrams(strs);

    for(int i=0; i<res.size(); i++){
        printVector(res[i]);
    }

    return 0;
}


