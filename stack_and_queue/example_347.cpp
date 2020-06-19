//
// Created by 陈志明 on 2020/5/22.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include "print.h"
using namespace std;

/**
 * 题目描述：前k个高频元素
 * 考点：堆
 * 是否做出：否
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k <= 0) return {};
        unordered_map<int, int> num_freq;

        // 统计数字出现频率
        for(int i = 0; i < nums.size(); i++){
            num_freq[nums[i]]++;
        }
        if(k > num_freq.size()) return {};

        // 按照频率大小建立堆，堆中维护k个元素，每次将频率最小的元素出堆；pair先按照第一个元素排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for(unordered_map<int, int>::iterator it = num_freq.begin(); it != num_freq.end(); it++){
            if(heap.size() == k){
                if(it->second > heap.top().first){
                    heap.pop();
                    heap.push(make_pair(it->second, it->first));
                }
            }
            else{
                heap.push(make_pair(it->second, it->first));
            }
        }

        vector<int> res;
        while(!heap.empty()){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};


int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    printVector(Solution().topKFrequent(nums, k));

    return 0;
}