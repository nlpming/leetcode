//
// Created by 陈志明 on 2021/8/22.
//

class Solution {
public:
    //判断是否字母或数字
    bool checkValid(char ch){
        if(isalpha(ch) || isdigit(ch)){
            return true;
        }else{
            return false;
        }
    }

    bool isPalindrome(string s) {
        if(s.length() == 0) return true;

        //注意：
        //1.判断是否字母：isaplha;
        //2.判断是否数字：isdigit; 头文件<cctype.h>
        //3.字母转成小写：tolower; 头文件<cctype.h>

        int left = 0, right = s.length()-1;
        while(left < right){
            if(!checkValid(s[left])) {
                left++;
            }else if(!checkValid(s[right])){
                right--;
            }else{
                if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }else{
                    left++;
                    right--;
                }
            }
        }

        return true;
    }
};