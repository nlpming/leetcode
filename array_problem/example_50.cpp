//
// Created by 陈志明 on 2020/5/8.
//
#include <iostream>
using namespace std;

/**
 * 题目描述：pow(x,n)
 * 考点：二分查找
 * 是否做出：是
 */
class Solution {
public:
    double myPow(double x, long n) {
        // 递归终止条件
        if(n == 0)
            return 1;

        // n为负数情况
        if(n < 0)
            return 1/myPow(x, -n);

        // n为奇偶区别对待
        double mid = myPow(x, n/2);
        if(n%2 == 0)
            return mid * mid;
        else
            return x * mid * mid;
    }
};

int main(){

    Solution s;
    cout<<s.myPow(2, 10)<<endl;

    return 0;
}





