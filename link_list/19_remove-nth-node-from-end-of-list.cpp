//
// Created by 陈志明 on 2021/8/25.
//

/*
 * 考点：链表 + 滑动窗口指针
 * */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;

        ListNode *cur = new_head, *next = new_head;
        //NOTE: next先移动n个位置；
        while(next != NULL && n > 0){
            next = next->next;
            n--;
        }

        //NOTE: 然后cur, next同步移动；【找到待删除结点的上一个结点；】
        while(next != NULL && next->next != NULL){
            cur = cur->next;
            next = next->next;
        }

        //NOTE: 删除结点；
        ListNode *s = cur->next;
        cur->next = s->next;
        delete s;

        return new_head->next;
    }
};