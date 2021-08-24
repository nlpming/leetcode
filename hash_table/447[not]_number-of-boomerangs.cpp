//
// Created by 陈志明 on 2021/8/24.
//

class Solution {
public:
    long getDistance(vector<int> p1, vector<int> p2){
        //NOTE: 此处不能使用pow函数，返回的类型为double；
        return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;

        for(int i = 0; i < points.size(); i++){
            // 1. 找到和points[i]这个点，距离相同的点的个数；
            unordered_map<long, int> record; //NOTE: key为距离，value为距离相同的点的个数；
            for(int j = 0; j < points.size(); j++){
                if(j == i) continue;
                record[getDistance(points[i], points[j])]++;
            }

            // 2. 计算得到最终的结果；
            for(unordered_map<int, int>::iterator it = record.begin(); it != record.end(); it++){
                if(it->second >= 2){
                    res += it->second * (it->second - 1);
                }
            }
        }

        return res;
    }
};