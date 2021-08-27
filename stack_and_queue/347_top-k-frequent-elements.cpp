//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：堆
 * 时间复杂度：O(nlogk)
 * */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //建立一个最小堆；【只存放k个元素】
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        //记录每个数字出现频率；
        unordered_map<int, int> record;
        for(int i = 0; i < nums.size(); i++){
            record[nums[i]]++;
        }

        //将数字压入堆中；【注意：first为频率, second为元素值】
        vector<int> res;
        for(unordered_map<int,int>::iterator it = record.begin(); it != record.end(); it++){
            if(pq.size() < k){
                pq.push(make_pair(it->second, it->first));
            }else{
                int freq = pq.top().first;
                int num = pq.top().second;
                if(freq < it->second){ //频率比较
                    pq.pop();
                    pq.push(make_pair(it->second, it->first));
                }
            }
        }

        while(!pq.empty()){
            int num = pq.top().second;
            res.push_back(num);

            pq.pop();
        }
        return res;
    }
};