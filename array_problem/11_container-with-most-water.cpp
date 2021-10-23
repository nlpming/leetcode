//
// Created by 陈志明 on 2021/8/22.
//

/*
 * 考点：对撞指针；
 * 难度：**
 * */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max_area = 0;

        //注意：
        //1. 比较height[left],height[right]：每次移动取值小的指针，保留最大的一个不移动；
        //2. 面积：(right-left)*min(height[left], height[right])
        //3. 解题思路：每次移动一个单元距离，保留最大的高度；才有可能找到最大的面积；

        while(left < right){
            max_area = max(max_area, (right-left)*min(height[left], height[right]));

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return max_area;
    }
};