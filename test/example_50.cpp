//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>

using namespace std;

class Solution{
public:
    double myPow(double x, long n){
        // n设置为long类型，不然会出现整形溢出
        if(n == 0)
            return 1;

        if(n < 0)
            return 1/myPow(x, -n);

        // 二分查找
        double mid = myPow(x, n/2);

        // 奇偶区别对待
        if(n%2 == 0)
            return mid * mid;
        else
            return x * mid * mid;
    }
};

int main(){
    cout << Solution().myPow(3, 2) << endl;

    return 0;
}