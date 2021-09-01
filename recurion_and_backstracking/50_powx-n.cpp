//
// Created by 陈志明 on 2021/8/31.
//

class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0)
            return 1.0;

        if(n < 0){
            n = -n;
            x = 1.0/x;
        }

        double res = myPow(x, n/2);
        if(n%2 == 0)
            return res*res;
        else
            return x*res*res;
    }
};