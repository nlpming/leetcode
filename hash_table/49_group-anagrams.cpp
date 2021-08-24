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

        vector<vector<string>> res;
        unordered_map<string, int> record;

        int idx = 0;
        for(int i = 0; i < strs.size(); i++){
            //NOTE: 存放原始字符串；
            string origin_str(strs[i].begin(), strs[i].end());

            //NOTE: 对字符串进行排序；
            sort(strs[i].begin(), strs[i].end());

            if(record.find(strs[i]) != record.end()){
                res[record[strs[i]]].push_back(origin_str);
            }else{
                vector<string> tmp;
                tmp.push_back(origin_str);

                res.push_back(tmp);
                record[strs[i]] = idx;
                idx++;
            }
        }

        return res;
    }
};


