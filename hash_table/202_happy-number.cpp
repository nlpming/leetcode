//
// Created by 陈志明 on 2021/8/23.
//
#include <iostream>
#include <unordered_set>
using namespace std;

/*
 * 考点：哈希表
 * 难度：**
 * */
class Solution {
public:
    int helper(int n){
        int sum = 0;
        while(n != 0){
            int mod = n%10;
            sum += mod*mod;
            n = n/10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> record; //记录是否产生无限循环；
        while(true){
            int tmp = helper(n);
            if(tmp == 1)
                return true;

            //记录是否生成过；
            if(record.find(tmp) != record.end())
                return false;
            else
                record.insert(tmp);

            n = tmp;
        }
    }
};

int main(){

    Solution s;
    cout << s.isHappy(19) << endl;

    return 0;
}