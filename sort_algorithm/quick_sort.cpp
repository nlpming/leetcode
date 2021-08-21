//
// Created by 陈志明 on 2020/11/5.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int left, int right){
    int pivot = nums[left];

    // nums[left], nums[right] 和 pivot进行大小对比
    while(left < right){
        while(left < right && nums[right] >= pivot)
            right--;
        nums[left] = nums[right];

        while(left < right && nums[left] <= pivot)
            left++;
        nums[right] = nums[left];
    }

    nums[left] = pivot;
    return left;
}


void quickSort(vector<int>& nums, int left, int right){
    if(left < right){
        int pivot_idx = partition(nums, left, right);
        quickSort(nums, left, pivot_idx-1);
        quickSort(nums, pivot_idx+1, right);
    }
}

void printVector(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }

    cout << endl;
}


int main(){

    vector<int> nums = {1,4,5,5,3,2,8};

    printVector(nums);
    quickSort(nums, 0, nums.size()-1);
    printVector(nums);

    return 0;
}


