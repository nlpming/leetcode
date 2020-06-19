//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int total = 0;
        int min_len = nums.size()+1;

        while(left < right || right == 0){
            if(total < s && right < nums.size()){
                total += nums[right];
                right++;
            }
            else{
                cout << left << "," << right << "," << total << endl;

                if(right-left < min_len && total >= s)
                    min_len = right-left;

                left++;
                total -= nums[left];
            }
        }

        if(min_len == nums.size()+1)
            return 0;
        return min_len;
    }
};

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    cout << Solution().minSubArrayLen(target, nums) << endl;

    return 0;
}

