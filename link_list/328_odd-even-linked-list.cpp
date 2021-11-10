//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表
 * 难度：**
 * */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *leftHead = new ListNode(0), *left = leftHead;
        ListNode *rightHead = new ListNode(0), *right = rightHead;

        int flag = 1;
        ListNode *cur = head;
        while(cur != NULL){
            if(flag%2 != 0){
                left->next= cur;
                left = cur;
            }else{
                right->next = cur;
                right = cur;
            }

            cur = cur->next;
            flag++;
        }

        left->next = rightHead->next;
        right->next = NULL;
        return leftHead->next;
    }
};

