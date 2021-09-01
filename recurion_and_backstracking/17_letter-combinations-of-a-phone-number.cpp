//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：回溯算法
 * 时间复杂度：O(2^n) - O(3^n)
 * */
class Solution {
public:
    vector<string> res;
    vector<string> recordVector = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void helper(string digits, int index, string& tmp){
        //NOTE: 递归终止条件；
        if(index == digits.size()){
            res.push_back(tmp);
            return;
        }

        //解题思路：
        //1. index记录当前处理第几个字符；
        //2. tmp用于存储中间结果；

        //NOTE: 注意0,1的处理；
        int curIdx = digits[index] - '0';
        if(curIdx < 0 || curIdx >= recordVector.size())
            return;

        string str = recordVector[curIdx];
        for(int i = 0; i < str.size(); i++){
            tmp.push_back(str[i]);
            helper(digits, index+1, tmp);
            tmp.pop_back(); //回溯过程；
        }

        return;
    }

    //方法一：递归 + 回溯算法（深度优先搜索）
    vector<string> letterCombinations_one(string digits) {
        if(digits.size() == 0)
            return res;

        string tmp = "";
        helper(digits, 0, tmp);

        return res;
    }

    //方法二：非递归 + 队列；（广度优先搜索）
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return res;

        //压入第一个数字映射字母；
        queue<pair<int, string>> record;
        int curIdx;

        curIdx = digits[0] - '0';
        for(int i = 0; i < recordVector[curIdx].size(); i++){
            string tmp = "";
            tmp.push_back(recordVector[curIdx][i]);
            record.push(make_pair(0, tmp));
        }

        while(!record.empty()){
            int size = record.size();
            for(int i = 0; i < size; i++){
                int index = record.front().first;
                string tmp = record.front().second;
                record.pop();

                if(index+1 == digits.size()){
                    res.push_back(tmp);
                    continue;
                }

                //下一个字符位置；
                string str = recordVector[digits[index+1] - '0'];
                for(int i = 0; i < str.size(); i++){
                    record.push(make_pair(index+1, tmp + string(1, str[i])));
                }
            }
        }

        return res;
    }
};