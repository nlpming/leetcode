//
// Created by 陈志明 on 2021/8/24.
//

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left, *left_rear, *right, *right_rear;
        ListNode *cur = head;

        //NOTE: 新建两个头结点；
        left = new ListNode(0);
        right = new ListNode(0);
        left_rear = left; right_rear = right;

        //NOTE: left链表存放小于x的元素；right链表存放大于等于x的元素；
        while(cur){
            ListNode *s = new ListNode(cur->val);

            if(cur->val < x){
                s->next = left_rear->next;
                left_rear->next = s;
                left_rear = s;
            }else{
                s->next = right_rear->next;
                right_rear->next = s;
                right_rear = s;
            }

            cur = cur->next;
        }

        left_rear->next = right->next;
        return left->next;
    }
};