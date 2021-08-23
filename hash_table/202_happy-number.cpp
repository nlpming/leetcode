//
// Created by 陈志明 on 2021/8/23.
//
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> record;
        int x, sum = 0;

        for(;;){
            //获取n的每一位数，得到最终的计算结果；
            while(n != 0){
                x = n%10;
                sum += x*x;
                n = n/10;
            }

            if(sum == 1){
                return true;
            }

            n = sum;
            if(record.find(sum) == record.end()){
                record.insert(sum);
                sum = 0;
            }else{
                return false;
            }
        }

        return false;
    }
};

int main(){

    Solution s;
    cout << s.isHappy(19) << endl;

    return 0;
}