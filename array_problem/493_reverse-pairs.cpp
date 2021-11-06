//
// Created by 陈志明 on 2021/9/2.
//

/*
 * 考点：归并排序、分治算法；
 * 难度：****
 * */
class Solution {
public:
    void merge(vector<int>& nums, int left, int right){
        int mid = left + (right-left)/2;
        int p1 = left, p2 = mid+1;
        int p = 0;

        vector<int> res(right-left+1);
        while(p1 <= mid || p2 <= right){
            if(p1 > mid)
                res[p++] = nums[p2++];
            else if(p2 > right)
                res[p++] = nums[p1++];
            else{
                if(nums[p1] < nums[p2])
                    res[p++] = nums[p1++];
                else
                    res[p++] = nums[p2++];
            }
        }

        for(int i = 0; i < res.size(); i++){
            nums[left + i] = res[i];
        }

        return;
    }

    //归并排序；
    int helper(vector<int>& nums, int left, int right){
        if(left == right)
            return 0;

        //左、右翻转对数；
        int mid = (left + right) / 2;
        int left_num = helper(nums, left, mid);
        int right_num = helper(nums, mid + 1, right);
        int ret = left_num + right_num;

        //交叉翻转对数；
        int i = left;
        int j = mid + 1;
        while (i <= mid) {
            while (j <= right && (long long)nums[i] > 2 * (long long)nums[j])
                j++;
            ret += (j - mid - 1);
            i++;
        }

        //合并两个排序好的数组；
        merge(nums, left, right);
        return ret;
    }

    //时间复杂度：O(nlogn)；
    //空间复杂度：O(n)；
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return helper(nums, 0, nums.size()-1);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,2,3,1};

    cout << s.reversePairs(nums) << endl;
    return 0;
}


