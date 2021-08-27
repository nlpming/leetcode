//
// Created by 陈志明 on 2021/8/27.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int getDiff(string s1, string s2){
        //NOTE: 判断是否相差一个字符；
        int diff = 0;

        if(s1.size() != s2.size()) return false;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                diff++;
            }

            if(diff > 1) {
                return diff;
            }
        }
        return diff;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int, string>> record;
        record.push(make_pair(1, beginWord));

        while(!record.empty()){
            int num = record.front().first;
            string curStr = record.front().second;
            record.pop();

            if(curStr == endWord){
                return num;
            }

            //NOTE: 将与curStr相差一个字符的string压入队列中；
            vector<string> wordListNew;
            for(int i = 0; i < wordList.size(); i++){
                // curStr是否出现在wordDict中；【注意此处】
                int diff = getDiff(curStr, wordList[i]);
                if(diff == 0) {
                    continue;
                }

                if(diff == 1){
                    record.push(make_pair(num+1, wordList[i]));
                }else{
                    wordListNew.push_back(wordList[i]);
                }
            }

            //NOTE: 删除wordList中已被访问的string 【此处可以缩短耗时】
            wordList = wordListNew;
        }

        return 0;
    }
};

int main(){
    Solution s;
    string beginWord = "hot", endWord = "dog";
    vector<string> wordList = {"hot","cog","dog","tot","hog","hop","pot","dot"};

    cout << s.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}



