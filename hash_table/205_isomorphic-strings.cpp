//
// Created by 陈志明 on 2021/10/25.
//

/*
 * 考点：映射Map；
 * 难度：*
 * */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> left;
        unordered_map<char, char> right;

        //注意：
        // 使用left存放 s -> t 的字母映射；
        // 使用right存放 t -> s 的字母映射；

        if(s.size() != t.size())
            return false;

        for(int i = 0; i < s.size(); i++){
            if(left.find(s[i]) != left.end()){
                if(left[s[i]] != t[i])
                    return false;
            }else{
                left[s[i]] = t[i];
            }

            if(right.find(t[i]) != right.end()){
                if(right[t[i]] != s[i])
                    return false;
            }else{
                right[t[i]] = s[i];
            }
        }

        return true;
    }
};