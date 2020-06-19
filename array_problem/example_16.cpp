//
// Created by 陈志明 on 2020/5/13.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/**
 * 题目描述：最接近的三数之和
 * 考点：数组，三指针
 * 是否做出：否
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        assert(nums.size() >= 3);
        sort(nums.begin(), nums.end());
        int closest_num = nums[0] + nums[1] + nums[2];

        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size()-1;

            while(left < right){
                // 找到与target最接近的三数之和
                int three_sum = nums[i]+nums[left]+nums[right];
                if(abs(three_sum-target) < abs(closest_num-target))
                    closest_num = three_sum;

                if(three_sum > target)
                    right--;
                else if(three_sum < target)
                    left++;
                else
                    break;
            }
        }
        return closest_num;
    }
};

int main(){
    vector<int> nums={-1,2,1,-4};
    int target=1;

    cout<<Solution().threeSumClosest(nums, target)<<endl;

    return 0;
}