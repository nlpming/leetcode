//
// Created by 陈志明 on 2021/8/26.
//

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int left, right, res = 0;

        for(int i = 0; i < tokens.size(); i++){
            //NOTE: 判断是否运算符；
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                left = nums.top(); nums.pop();
                right = nums.top(); nums.pop();

                if(tokens[i][0] == '*'){
                    res = right * left;
                }else if(tokens[i][0] == '+'){
                    res = right + left;
                }else if(tokens[i][0] == '-'){
                    res = right - left;
                }else if(tokens[i][0] == '/'){
                    res = right / left;
                }

                //NOTE: 计算结果压入栈中；
                nums.push(res);
            }else{
                nums.push(stoi(tokens[i]));
            }
        }

        return nums.top();
    }
};