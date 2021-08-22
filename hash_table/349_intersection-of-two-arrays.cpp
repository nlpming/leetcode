//
// Created by 陈志明 on 2021/8/22.
//

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> record1, record2;
        vector<int> res;

        if(nums1.size() == 0 || nums2.size() == 0)
            return res;

        //nums1中的元素存入record1中；
        for(int i = 0; i < nums1.size(); i++){
            if(!record1.count(nums1[i])){
                record1.insert(nums1[i]);
            }
        }

        //遍历nums2，判断元素是否在record1中出现；出现则将其放入record2中；
        for(int j = 0; j < nums2.size(); j++){
            if(record1.count(nums2[j])){
                record2.insert(nums2[j]);
            }
        }

        //遍历unordered_set中的元素，将其插入到res中；
        for(unordered_set<int>::iterator it = record2.begin(); it != record2.end(); it++){
            res.push_back(*it);
        }
        // NOTE: 另外一种简洁写法：res = vector<int>(record2.begin(), record2.end());

        return res;
    }
};