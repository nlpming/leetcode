//
// Created by 陈志明 on 2021/8/21.
//

/*
 * 考点：三指针
 * 难度：**
 * */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1;
        int last = m+n-1;

        //注意：
        // 1. 终止条件的判断：p1 >= 0 && p2 >= 0；
        // 2. last指针指向数组的最大的元素；
        // 3. 如果p2 >= 0需要继续插入数据到nums中；p1不需要这样的处理；
        while(p2 >= 0 && p1 >= 0){
            if(nums1[p1] > nums2[p2]){
                nums1[last] = nums1[p1];
                p1--;
            }else{
                nums1[last] = nums2[p2];
                p2--;
            }

            last--;
        }

        while(p2 >= 0){
            nums1[last] = nums2[p2];
            last--;
            p2--;
        }
    }
};