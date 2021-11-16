//
// Created by 陈志明 on 2021/8/24.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
 * 考点：滑动窗口（窗口中元素排序）+ 哈希表；
 * 难度：***
 * 时间复杂度：O(nlogn)
 * */
class Solution {
public:
    /*
     * 解题思路：
     * 1. record存放窗口(left, right]中的数据；
     * 2. 对于下一个位置right+1的元素，判断record是否存在满足 x-t <= v <= x+t的元素；
     * 3.（1）如果不存在则将right+1位置元素入record中；
     * 4.（2）否则left++，去除left指向的元素；判断解是否存在。
     * */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() == 0) return false;

        //NOTE: 底层实现为平衡二叉树，set中的元素是有序的，所以可以调用lower_bound等方法；
        int left = -1, right = 0;
        set<long> record{nums[0]}; //set初始化；

        while(right+1 < nums.size()){
            //NOTE: 是否能够找到一个元素v满足条件：x-t <= v <= x+t;【注意整形越界问题】
            long low_data = long(nums[right+1]) - t;
            long upper_data = long(nums[right+1]) + t;

            //NOTE: lower_bound()函数用于在指定区域内查找大于等于目标值的元素位置指针。
            if(!(record.lower_bound(low_data) != record.end()
                && *record.lower_bound(low_data) <= upper_data)) {
                right++;
                record.insert(nums[right]);
            }else{
                left++;
                record.erase(nums[left]);

                //比较：nums[left], nums[right+1]这两个元素是否满足问题解；
                if(abs(nums[left] - nums[right+1]) <= t && abs(right+1-left) <= k){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};

    cout << s.containsNearbyAlmostDuplicate(nums, 3, 0) << endl;

    return 0;
}