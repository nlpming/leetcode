//
// Created by 陈志明 on 2020/5/11.
//
#include <iostream>
#include <unordered_set>
#include "print.h"
using namespace std;

/**
 * 题目描述：快乐数
 * 考点：数组、集合
 * 是否做出：否
 */
class Solution {
public:
    bool isHappy(int n) {
        // 记录已经计算过的数字
        unordered_set<int> order;

        while(n != 1){
            if(order.find(n) != order.end())
                return false;
            order.insert(n);
            n = getValue(n);
        }

        return true;
    }

    int getValue(int n){
        int res=0;

        while(n){
            int m = n%10;
            res += m*m;
            n = n/10;
        }
        return res;
    }
};


int main(){
    cout<<Solution().isHappy(8)<<endl;

    return 0;
}