//
// Created by 陈志明 on 2021/8/24.
//

/*
 满足条件：
 （1）abs(nums[i] - nums[j]) <= t;
 （2）abs(i - j) <= k;
 */

/*
 * 考点：滑动窗口 + 哈希表 + lower_bound；
 * 难度：***
 * */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() == 0) return false;

        int left = -1, right = 0;
        set<long> record; //NOTE: 底层实现为平衡二叉树，set中的元素是有序的，所以可以调用lower_bound等方法；
        record.insert(nums[0]);

        while(right+1 < nums.size()){
            //NOTE: 是否能够找到一个元素v满足条件：x-t <= v <= x+t;
            long low_data = long(nums[right+1]) - t;
            long upper_data = long(nums[right+1]) + t;

            //NOTE: lower_bound用于查找一个有序序列中，大于等于某个元素的迭代器；
            if(!(record.lower_bound(low_data) != record.end() && *record.lower_bound(low_data) <= upper_data)) {
                right++;
                record.insert(nums[right]);
            }else{
                left++;
                record.erase(nums[left]);

                if(abs(nums[left] - nums[right+1]) <= t && abs(right+1-left) <= k){ //NOTE: 注意此处边界处理
                    return true;
                }
            }
        }

        return false;
    }
};