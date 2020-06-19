//
// Created by 陈志明 on 2020/5/21.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * 题目描述：字符串接龙
 * 考点：队列、广度优先搜索
 * 是否做出：否
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);

        int res = 0;
        while(!q.empty()){
            res++;
            // 每次将当前层，所有结点都出队列；然后将当前层，后续结点入队列
            for(int sz = q.size(); sz > 0; sz--){
                string top = q.front();
                if(top == endWord) return res;
                q.pop();

                for(int ws = 0; ws < wordList.size(); ws++){
                    string w = wordList[ws];
                    // 计算diff，小于等于1入队列
                    if(w.empty() || w.length() != beginWord.length()) continue;
                    int diff = 0;
                    for(int i = 0; i < w.length(); i++){
                        if(w[i] != top[i]) ++diff;
                        if(diff > 1) break;
                    }
                    if(diff <= 1) {
                        q.push(w);
                        w = ""; // 访问过的单词置空，不再访问
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout<<Solution().ladderLength(beginWord, endWord, wordList);


    return 0;
}