//
// Created by 陈志明 on 2021/10/26.
//

class Solution {
public:
    /*
     * 时间复杂度：O(n);
     * 空间复杂度：O(n);
     */
    int countBinarySubstrings_m1(string s) {
        vector<int> counts;
        int cur = 0;

        //按照字符进行分组；"00111011" -> [2,3,1,2]
        while(cur < s.size()){
            int count = 0;
            char ch = s[cur];
            while(s[cur] == ch){
                cur++;
                count++;
            }

            counts.push_back(count);
        }

        //统计得到结果；
        int res = 0;
        for(int i = 1; i < counts.size(); i++){
            res += min(counts[i], counts[i-1]);
        }

        return res;
    }

    /*
     * 时间复杂度：O(n);
     * 空间复杂度：O(1);
     */
    int countBinarySubstrings(string s) {
        int cur = 0, last = 0, res = 0;

        //按照字符进行分组；"00111011" -> [2,3,1,2]
        while(cur < s.size()){
            int count = 0;
            char ch = s[cur];
            while(s[cur] == ch){
                cur++;
                count++;
            }

            res += min(last, count);
            last = count;
        }

        return res;
    }
};