//
// Created by 陈志明 on 2020/6/8.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> visited;

    void generatePermute(vector<int> nums, int index, vector<int> temp){
        if(index == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                temp.push_back(nums[i]);
                visited[i] = true;
                generatePermute(nums, index+1, temp);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return res;

        visited = vector<bool>(nums.size(), false);
        vector<int> temp;
        generatePermute(nums, 0, temp);

        return res;
    }
};

