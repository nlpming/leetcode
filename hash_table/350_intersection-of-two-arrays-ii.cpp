//
// Created by 陈志明 on 2021/8/22.
//

/*
示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

示例 2:
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;

        //NOTE: map对应的value有默认值0；【即使key不存在，c++中map也不会报错】
        for(int i = 0; i < nums1.size(); i++)
            record[nums1[i]]++;

        vector<int> res;
        for(int j = 0; j < nums2.size(); j++){
            if(record[nums2[j]] > 0){
                res.push_back(nums2[j]);
                record[nums2[j]]--;
            }
        }

        return res;
    }
};