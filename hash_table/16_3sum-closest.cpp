//
// Created by 陈志明 on 2021/11/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int res = INT_MAX;
        int minGap = INT_MAX; //存放最小的gap；
        for(int cur = 0; cur < nums.size(); cur++){
            if(cur > 0 && nums[cur] == nums[cur-1]) //去重
                continue;

            int left = cur+1;
            int right = nums.size()-1;
            while(left < right){
                int value = nums[cur] + nums[left] + nums[right];
                if(abs(value - target) < minGap){
                    minGap = abs(value - target);
                    res = value;
                }

                if(value < target)
                    left++;
                else
                    right--;
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