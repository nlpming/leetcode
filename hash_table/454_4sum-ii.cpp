//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：哈希表
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n^2)
 * */
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> record;
        int res = 0;

        //NOTE: 将A[i] + B[j]之和放入record中，并记录总共有多少种可能组合；
        // key -> 两数之和，value -> 和相同的数量；
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                record[nums1[i] + nums2[j]]++;
            }
        }

        //NOTE: 结果可以存在重复；
        for(int i = 0; i < nums3.size(); i++){
            for(int j = 0; j < nums4.size(); j++){
                int target = -(nums3[i] + nums4[j]);
                if(record.find(target) != record.end()){
                    res += record[target];
                }
            }
        }

        return res;
    }
};


