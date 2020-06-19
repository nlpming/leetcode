//
// Created by 陈志明 on 2020/5/11.
//
#include <iostream>
#include <vector>
#include <map>
#include "print.h"
using namespace std;

/**
 * 题目描述：两个数组的交集II
 * 考点：数组、哈希表
 * 是否做出：是
 * NOTE: 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nums_freq; // 可以使用 unordered_map
        vector<int> res;

        // nums_freq: 存储nums1中数字及其出现的频率
        for(int i=0; i<nums1.size(); i++){
            if(nums_freq.find(nums1[i]) == nums_freq.end())
                nums_freq[nums1[i]] = 0;
            nums_freq[nums1[i]]++;
        }

        for(int i=0; i<nums2.size(); i++){
            if(nums_freq.find(nums2[i]) != nums_freq.end()){
                if(nums_freq[nums2[i]] > 0){
                    res.push_back(nums2[i]);
                    nums_freq[nums2[i]]--;
                }
            }
        }

        return res;
    }
};

int main(){
    vector<int> nums1={4,9,5}, nums2={9,4,9,8,4};
    printVector(Solution().intersect(nums1, nums2));

    return 0;
}

