//
// Created by 陈志明 on 2021/8/24.
//

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1, s2;
        //NOTE: 先将链表数据存入栈中；【注意：使用栈存储两个链表中的数据】
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }

        //NOTE: 然后生成链表；
        int flag = 0;
        ListNode *s;
        ListNode *head = new ListNode(0);

        while(!s1.empty() || !s2.empty()){
            int data = 0;
            if(!s1.empty()){
                data += s1.top(); //NOTE: 取栈顶元素；
                s1.pop(); //NOTE: 出栈操作；
            }
            if(!s2.empty()){
                data += s2.top();
                s2.pop();
            }

            if(flag){
                data += flag;
                flag = 0;
            }

            if(data < 10){
                s = new ListNode(data);
                s->next = head->next;
                head->next = s;
            }else{
                s = new ListNode(data%10); //NOTE：注意和大于10的情况；
                s->next = head->next;
                head->next = s;
                flag = 1;
            }
        }

        if(flag){ //NOTE：注意此处的处理；还需要在进一位；
            s = new ListNode(1);
            s->next = head->next;
            head->next = s;
        }

        return head->next;
    }
};