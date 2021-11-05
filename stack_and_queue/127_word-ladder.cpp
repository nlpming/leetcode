//
// Created by 陈志明 on 2021/11/4.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

/*
 * 考点：广度优先搜索、队列、哈希表；最短路径问题；
 * 难度：***
 * */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int, string>> record;
        record.push(make_pair(1, beginWord));

        unordered_set<string> visited;
        visited.insert(beginWord);

        //wordList单词集合；
        unordered_set<string> wordSet;
        for(int i = 0; i < wordList.size(); i++)
            wordSet.insert(wordList[i]);

        while(!record.empty()){
            int size = record.size();
            for(int i = 0; i < size; i++){
                int number = record.front().first;
                string str = record.front().second;
                record.pop();

                //找到问题答案；
                if(str == endWord)
                    return number;

                //NOTE：尝试每次修改一个字符；【注意此处的技巧】
                for(int j = 0; j < str.size(); j++){
                    char originChar = str[j];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(ch == originChar)
                            continue;
                        str[j] = ch;

                        //（1）wordSet中存在；（2）并且str没有被访问过；
                        if(wordSet.find(str) != wordSet.end() && visited.find(str) == visited.end()){
                            record.push(make_pair(number+1, str));
                            visited.insert(str);
                        }
                    }
                    str[j] = originChar; //还原；
                }
            }
        }

        return 0;
    }
};

int main(){

    Solution s;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << s.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
