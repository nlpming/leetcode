//
// Created by 陈志明 on 2021/8/22.
//

/*
 * 考点：对撞指针；
 * 难度：*
 * */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        vector<int> res;

        //注意：
        //1.left指针初始化为0，right指针初始化为nums.size()-1;
        //2.left, right相向移动，如果nums[left] + nums[right] == target则返回（left+1, right+1）；
        //3.输入的是排序好的数据，相似题目未排序数组；

        while(left < right){
            if(numbers[left] + numbers[right] == target){
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }else if(numbers[left] + numbers[right] > target){
                right--;
            }else{
                left++;
            }
        }

        return res;
    }
};

