//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表；
 * 难度：**
 * */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2, *s;
        ListNode *head = new ListNode(0), *rear = head;
        int flag = 0;

        while(p != NULL || q != NULL){
            //NOTE: 判断p,q是否为NULL，得到最终的计算结果；
            int data = 0;
            if(p != NULL){
                data += p->val;
                p = p->next;
            }
            if(q != NULL){
                data += q->val;
                q = q->next;
            }

            if(flag){ //判断是否前面的数相加大于10；
                data += flag;
                flag = 0;
            }

            if(data < 10){ //NOTE: 判断两数之和是否大于10，大于则需要进位；
                s = new ListNode(data);
                rear->next = s;
                rear = s;
            }else{
                flag = 1;
                s = new ListNode(data%10);
                rear->next = s;
                rear = s;
            }
        }

        //NOTE: p和q都为空，但是flag不为0；【注意此处】
        if(flag){
            s = new ListNode(1);
            rear->next = s;
            rear = s;
        }

        return head->next;
    }
};