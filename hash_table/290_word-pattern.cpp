//
// Created by 陈志明 on 2021/8/23.
//

/*
输入: pattern = "abba", str = "dog cat cat dog"
输出: true
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> parseString(string s){
        vector<string> res;

        string tmp;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                res.push_back(tmp);
                tmp.clear();
            }else{
                tmp.push_back(s[i]);
            }
        }

        if(!tmp.empty())
            res.push_back(tmp);

        return res;
    }

    bool wordPattern(string pattern, string s) {

        vector<string> result = parseString(s);
        if(result.size() != pattern.length()){
            return false;
        }

        //创建两个map，记录【char -> string】, 【string -> char】的映射关系；
        unordered_map<char, string> record;
        unordered_map<string, char> record_reverse;

        for(int i = 0; i < pattern.size(); i++){
            //(char, string)在两个map中都不存在；
            if(record.find(pattern[i]) == record.end() && record_reverse.find(result[i]) == record_reverse.end()){
                record[pattern[i]] = result[i];
                record_reverse[result[i]] = pattern[i];
            }else{
                if(record.find(pattern[i]) != record.end() && record[pattern[i]] != result[i]){
                    return false;
                }

                if(record_reverse.find(result[i]) != record_reverse.end() && record_reverse[result[i]] != pattern[i]){
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){

    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;

    return 0;
}







