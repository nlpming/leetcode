//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表 + 增加虚拟头结点；
 * 难度：*
 * */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        ListNode *cur = newHead, *s;
        while(cur->next != NULL){
            if(cur->next->val == val){
                s = cur->next;
                cur->next = cur->next->next;
                delete s;
            }else{
                cur = cur->next;
            }
        }

        return newHead->next;
    }
};