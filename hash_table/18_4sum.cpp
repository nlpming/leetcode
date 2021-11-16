//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：数组；
 * 难度：***
 * */
class Solution {
public:
    /*
     * 解题思路：
     * 1. 将四数之和问题，转换为求解两数之和问题；
     * 2. 如何去重？
     * （1）对数组进行排序；
     * （2）对每一个位置a,b,c,d都进行去重操作；
     * */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        //数组进行排序
        sort(nums.begin(), nums.end());
        for(int a = 0; a < nums.size(); a++){
            if(a > 0 && nums[a] == nums[a-1]) //位置a去重；
                continue;

            for(int b = a+1; b < nums.size(); b++){
                if(b > a+1 && nums[b] == nums[b-1]) //位置b去重；
                    continue;

                int left = b+1;
                int right = nums.size()-1;

                //转换为求解两数之和问题；
                int value = target - nums[a] - nums[b];
                while(left < right){
                    if(nums[left] + nums[right] == value){
                        res.push_back({nums[a],nums[b],nums[left],nums[right]});
                        left++;
                        right--;

                        //位置c,d去重；
                        while(left < right && nums[left] == nums[left-1])
                            left++;
                        while(left < right && nums[right] == nums[right+1])
                            right--;
                    }else if(nums[left] + nums[right] > value)
                        right--;
                    else
                        left++;
                }
            }
        }

        return res;
    }
};