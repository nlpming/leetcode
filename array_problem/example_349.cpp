//
// Created by 陈志明 on 2020/5/11.
//
#include <iostream>
#include <vector>
#include <set>
#include "print.h"
using namespace std;

/**
 * 题目描述：两个数组的交集
 * 考点：数组、集合
 * 是否做出：是
 * NOTE: 输出结果中的每个元素一定是唯一的。
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 or nums2.size() == 0)
            return {};

        set<int> res;
        // 注意此处初始化 set 的方式
        set<int> num1_set(nums1.begin(), nums1.end());

        // 插入set相同的元素，只会保留一个
        for(int i=0; i<nums2.size(); i++){
            if(num1_set.find(nums2[i]) != num1_set.end()){
                res.insert(nums2[i]);
            }
        }

        // 使用 set 初始化 vector
        return vector<int>(res.begin(), res.end());
    }
};

int main(){
    vector<int> nums1={1,2,2,1}, nums2={2,2};
    printVector(Solution().intersection(nums1, nums2));

    return 0;
}