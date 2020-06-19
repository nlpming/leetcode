//
// Created by 陈志明 on 2020/5/14.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

/**
 * 题目描述：回旋镖的数量
 * 考点：哈希表
 * 是否做出：否
 * NOTE: 允许存在重复
 */
class Solution {
public:
    int calcDistance(vector<int> points1, vector<int> points2){
        return pow(points1[0]-points2[0], 2) + pow(points1[1]-points2[1], 2);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i=0; i<points.size(); i++){
            // 计算与points[i]距离相等的points
            unordered_map<int, int> record;
            for(int j=0; j<points.size(); j++){
                if(j != i){
                    int distance = calcDistance(points[i], points[j]);
                    record[distance] += 1;
                }
            }

            // 计算所有可能的组合
            for(unordered_map<int, int>::iterator it=record.begin(); it != record.end(); ++it){
                res += it->second*(it->second-1);
            }
        }
        return res;
    }
};


int main(){
    vector<vector<int>> points = {{0,0},{1,0},{2,0}};
    cout<<Solution().numberOfBoomerangs(points);

    return 0;
}


