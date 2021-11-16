//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：哈希表；
 * 难度：*
 * */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> record;
        for(int i = 0; i < strs.size(); i++){
            string tmp(strs[i].begin(), strs[i].end());
            sort(tmp.begin(), tmp.end()); //对字符串进行排序；

            if(record.find(tmp) == record.end()){
                record[tmp] = vector<string>{strs[i]};
            }else{
                record[tmp].push_back(strs[i]);
            }
        }

        //map的遍历；
        vector<vector<string>> res;
        for(unordered_map<string, vector<string>>::iterator it = record.begin(); it != record.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};


