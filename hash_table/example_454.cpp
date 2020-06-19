//
// Created by 陈志明 on 2020/5/14.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 题目描述：四数相加II
 * 考点：哈希表，灵活选择键值
 * 是否做出：是
 */
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // 使用无序的map，底层实现为哈希表
        unordered_map<int, int> sum_index_map;
        int res = 0;

        // C+D 所有可能结果存入map
        for(int i=0; i<C.size(); i++){
            for(int j=0; j<D.size(); j++){
                int total = C[i]+D[j];
                sum_index_map[total]++;
            }
        }

        // 遍历找到所有可能组合
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<B.size(); j++){
                int other = -(A[i]+B[j]);
                if(sum_index_map.find(other) != sum_index_map.end()){
                    res += sum_index_map[other];
                }
            }
        }

        return res;
    }
};

int main(){
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

    cout<<Solution().fourSumCount(A, B, C, D)<<endl;


    return 0;
}
