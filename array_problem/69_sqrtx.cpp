//
// Created by 陈志明 on 2021/10/24.
//

/*
 * 考点：二分查找；
 * 难度：**
 * */
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, res = -1;

        while(left <= right){
            int mid = left + (right-left)/2;
            if((long)mid*mid <= x){ //NOTE: 防止整形溢出；
                res = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return res;
    }
};