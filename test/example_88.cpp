//
// Created by 陈志明 on 2020/6/11.
//
#include <iostream>
#include <vector>
#include "print.h"

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m+n-1;
        int p = m-1;
        int q = n-1;

        // 注意终止条件
        while(q >= 0){
            cout << last << endl;

            if(p >= 0 && nums1[p] > nums2[q]){
                nums1[last] = nums1[p];
                p--;
                last--;
            }
            else{
                nums1[last] = nums2[q];
                q--;
                last--;
            }
        }

        return;
    }
};

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    printVector(nums1);
    printVector(nums2);

    Solution().merge(nums1, 3, nums2, 3);
    printVector(nums1);

    return 0;
}