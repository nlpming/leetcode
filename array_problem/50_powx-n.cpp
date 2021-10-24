//
// Created by 陈志明 on 2021/10/24.
//

/*
 * 考点：递归、二分查找；
 * 难度：**
 * */
class Solution {
public:
    double myPow(double x, long n) { //NOTE: 注意整形溢出；
        if(n == 0) return 1;

        //n为负数的时候；
        if(n < 0)
            return 1./myPow(x, -n);

        //先求解 x^(n/2);
        double mid = myPow(x, n/2);

        //n为奇偶的时候区别对待；
        if(n%2 == 0)
            return mid * mid;
        else
            return x * mid * mid;
    }
};