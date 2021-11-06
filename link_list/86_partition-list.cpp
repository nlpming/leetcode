//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表；
 * 难度：**
 * */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0), *leftRear = left;
        ListNode *right = new ListNode(0), *rightRear = right;

        ListNode *cur = head;
        while(cur != NULL){
            if(cur->val < x){
                leftRear->next = cur;
                leftRear = cur;
            }else{
                rightRear->next = cur;
                rightRear = cur;
            }

            cur = cur->next;
        }

        //left,right拼接在一起；
        leftRear->next = right->next;
        rightRear->next = NULL;

        return left->next;
    }
};