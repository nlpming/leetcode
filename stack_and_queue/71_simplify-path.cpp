//
// Created by 陈志明 on 2021/8/26.
//
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

/*
 * 考点：字符串分割 + 栈
 * 难度：***
 * 题名：71.简化路径
 * */
class Solution {
public:
    vector<string> stringSplit(string str, string pattern){
        vector<string> res;
        if(str.size() == 0) return res;

        //NOTE: 末尾补充pattern；
        str = str + pattern;
        int pos = str.find(pattern);

        //注意此处，到达字符串末尾的判断；
        while(pos != str.npos){
            string tmp = str.substr(0, pos); //可能为空；
            res.push_back(tmp);

            //NOTE: 截取pos之后的字符子串；
            str = str.substr(pos+1, str.size());
            pos = str.find(pattern);
        }

        return res;
    }

    string simplifyPath(string path) {
        stack<string> record;

        //解题思路：
        //1.首先实现path分割函数，得到vector<string>；
        //2.然后遍历vector<string>，将元素插入stack中；
        //3.最后基于stack，生成最终结果；

        //NOTE: 1.字符分割；
        vector<string> strs = stringSplit(path, "/");

        for(int i = 0; i < strs.size(); i++){
            //NOTE: 不为["",".",".."]入栈；
            if(strs[i] != "" && strs[i] != "." && strs[i] != ".."){
                record.push(strs[i]);
            }else if(strs[i] == ".." && !record.empty()){
                record.pop();
            }
        }

        //NOTE: 生成结果；
        string res;
        if(record.empty()) return "/"; //NOTE:注意此处；例子：/../
        while(!record.empty()){
            res = "/" + record.top() + res;
            record.pop();
        }

        return res;
    }
};

int main(){
    Solution s;

    cout << s.simplifyPath("/a/./b/../../c/") << endl;
    //cout << s.simplifyPath("/a/home/") << endl;


    return 0;
}



