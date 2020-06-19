//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty())
            return nums;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        unordered_map<int, int> mp;

        // 统计每个词出现的频率
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] += 1;
        }

        assert(k <= mp.size());
        for(unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
            if(heap.empty() || heap.size() < k){
                heap.push(make_pair(it->second, it->first));
            }
            else{
                int freq = heap.top().first;
                if(it->second > freq){
                    heap.pop();
                    heap.push(make_pair(it->second, it->first));
                }
            }
        }

        vector<int> res;
        while(!heap.empty()){
            int number = heap.top().second;
            res.push_back(number);
            heap.pop();
        }

        return res;
    }
};

int main(){


    return 0;
}
