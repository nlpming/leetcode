//
// Created by 陈志明 on 2020/6/23.
//
#include <iostream>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        if(x == 0)
            return x;

        long res = 0, mod = 0;
        while(x){
            mod = x % 10;
            res = res*10 + mod;

            x = x / 10;
        }

        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};

int main(){

    cout << Solution().reverse(-123) << endl;

    return 0;
}


