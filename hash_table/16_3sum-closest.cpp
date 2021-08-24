//
// Created by 陈志明 on 2021/8/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 考点：三指针；
 * */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;
        int min_gap = INT_MAX;

        sort(nums.begin(), nums.end());
        for(int cur = 0; cur < nums.size(); cur++){
            int left = cur+1;
            int right = nums.size()-1;

            while(left < right){
                int sum = nums[left]+nums[right]+nums[cur];

                //NOTE: 用于比较gap；
                if(abs(sum - target) < min_gap){
                    min_gap = abs(sum - target);
                    res = sum;
                }

                //NOTE: 让此和无限逼近0；
                if(sum - target > 0){
                    right--;
                }else{
                    left++;
                }
            }
        }

        return res;
    }
};

int main(){

    Solution s;
    vector<int> nums = {-1,2,1,-4};
    cout << s.threeSumClosest(nums, 1) << endl;

    return 0;
}


