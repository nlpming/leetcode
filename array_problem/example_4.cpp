//
// Created by 陈志明 on 2020/6/22.
//
#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> res;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()){
            res.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            res.push_back(nums2[j]);
            j++;
        }

        if(res.size()%2 != 0)
            return res[res.size()/2];
        else{
            int index = res.size()/2;
            return double(res[index-1] + res[index])/2;
        }
    }
};

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}