//
// Created by 陈志明 on 2021/8/24.
//

class Solution {
public:
    //两数之和: 数组已排好序
    vector<vector<int>> twoSum(vector<int> nums, int left, int right, int target){
        vector<vector<int>> res;
        unordered_map<int, int> record; //记录两个数

        while(left < right){
            if(nums[left] + nums[right] == target){
                if(record.find(nums[left]) == record.end() && record.find(nums[right]) == record.end()){
                    vector<int> tmp;
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);

                    record[nums[left]] = nums[right];
                }

                left++;
                right--;
            }else if(nums[left] + nums[right] > target){
                right--;
            }else{
                left++;
            }
        }

        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){ //NOTE: 去重
                continue;
            }

            for(int j = i+1; j < nums.size(); j++){
                if(j > i+1 && nums[j] == nums[j-1]){ //NOTE: 去重
                    continue;
                }

                int left = j+1;
                int right = nums.size()-1;
                vector<vector<int>> tmp;
                tmp = twoSum(nums, left, right, target - (nums[i]+nums[j]));
                if(tmp.size() != 0){
                    for(int k = 0; k < tmp.size(); k++){
                        tmp[k].push_back(nums[i]);
                        tmp[k].push_back(nums[j]);
                        res.push_back(tmp[k]);
                    }
                }
            }
        }

        return res;
    }
};