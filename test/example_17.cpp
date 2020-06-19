//
// Created by 陈志明 on 2020/6/8.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    const string lettersMap[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    void generateCombination(const string& digits, int index, string p) {
        if (index == digits.size()) {
            res.push_back(p);
            return;
        }

        char ch = digits[index];
        string letters = lettersMap[ch - '0'];
        for (int i = 0; i < letters.size(); i++) {
            p.push_back(letters[i]);
            generateCombination(digits, index + 1, p);
            p.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;

        string p;
        generateCombination(digits, 0, p);
        return res;
    }
};


