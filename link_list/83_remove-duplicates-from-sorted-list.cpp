//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表 + 双指针；
 * 难度：*
 * */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        ListNode *p = newHead, *q;
        while(p->next != NULL){
            q = p->next;

            //存在重复；
            if(q->next != NULL && p->next->val == q->next->val){
                p->next = q->next;
                delete q;
            }else{
                p = p->next;
            }
        }

        return newHead->next;
    }
};