//
// Created by 陈志明 on 2021/8/26.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 字符串分割；
 * */
vector<string> string_split(string str, string pattern){
    vector<string> res;
    if(str.length() == 0) return res;

    str = str + pattern;
    int pos = str.find(pattern);

    while(pos != str.npos){
        //NOTE: 可能为空；
        string tmp = str.substr(0, pos);
        res.push_back(tmp);

        str = str.substr(pos+1, str.size());
        pos = str.find(pattern);
    }

    return res;
}

int main()
{
    vector<string> res = string_split("/a/./b/../../c/", "/");
    for(int i = 0; i < res.size(); i++){
        cout << "|" << res[i] << "|" << "->";
    }
    cout << endl;

    return 0;
}