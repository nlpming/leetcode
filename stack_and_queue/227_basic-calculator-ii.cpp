//
// Created by 陈志明 on 2021/10/26.
//

/*
 * 考点：栈；
 * 难度：***
 * */
class Solution {
public:
    int calculate(string s) {
        stack<int> record;
        char preSign = '+';
        int num = 0;

        //注意：
        //1. 增加preSign表示，数字前面的运算符；
        //2. 遇到*,/计算结果，并将结果压入栈中；
        //3. 最终，求取栈中的元素之和；即为答案；

        for(int i = 0; i < s.size(); i++){
            //计算数字累计和；
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }

            //字符：对于*,/计算结果并压入栈中；【NOTE：注意 i=n-1 的情况】
            if((!isdigit(s[i]) && s[i] != ' ') || i == s.size()-1){
                if(preSign == '+'){
                    record.push(num);
                }else if(preSign == '-'){
                    record.push(-num);
                }else if(preSign == '*'){
                    int top = record.top();
                    record.pop();
                    record.push(top * num);
                }else if(preSign == '/'){
                    int top = record.top();
                    record.pop();
                    record.push(top / num);
                }

                preSign = s[i]; //更新运算符；
                num = 0;
            }
        }

        //将栈中的数字相加；
        int res = 0;
        while(!record.empty()){
            int top = record.top();
            res += top;
            record.pop();
        }

        return res;
    }
};