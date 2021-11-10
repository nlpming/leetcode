//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：栈 + 链表；
 * 难度：**
 * */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        //链表中元素放入栈中；
        ListNode *cur = l1;
        while(cur != NULL){
            s1.push(cur->val);
            cur = cur->next;
        }

        cur = l2;
        while(cur != NULL){
            s2.push(cur->val);
            cur = cur->next;
        }

        ListNode *newHead = new ListNode(0), *rear = newHead;
        int flag = 0, left, right;
        while(!s1.empty() || !s2.empty()){
            left = 0, right = 0;
            if(!s1.empty()){
                left = s1.top();
                s1.pop();
            }

            if(!s2.empty()){
                right = s2.top();
                s2.pop();
            }

            int val = left + right + flag;
            //判断是否大于10；
            if(val >= 10){
                val = val%10;
                flag = 1;
            }else{
                flag = 0;
            }

            //每次插入到头结点之后；
            ListNode *s = new ListNode(val);
            s->next = rear->next;
            rear->next = s;
        }

        //flag不为0的情况；
        if(flag){
            ListNode *s = new ListNode(flag);
            s->next = rear->next;
            rear->next = s;
        }

        return newHead->next;
    }
};