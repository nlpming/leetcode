//
// Created by 陈志明 on 2021/8/23.
//

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> record;

        for(int i = 0; i < s.length(); i++){
            record[s[i]]++;
        }

        for(int j = 0; j < t.length(); j++){
            if(record[t[j]] > 0){
                record[t[j]]--;
                if(record[t[j]] == 0)
                    record.erase(t[j]);
            }
        }

        if(record.size() == 0)
            return true;
        else
            return false;
    }
};