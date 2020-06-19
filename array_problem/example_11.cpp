//
// Created by 陈志明 on 2020/5/9.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：盛最多水的容器
 * 考点：数组，对撞指针
 * 是否做出：是
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int max_area=0, area=0;

        while(left < right){
            area = (right-left)*min(height[left], height[right]);
            if(area > max_area)
                max_area = area;

            // 值小的指针向内移动；向内移动距离肯定缩小，要保证height尽可能大；
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};

    Solution s;
    cout<<s.maxArea(height)<<endl;

    return 0;
}