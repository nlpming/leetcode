//
// Created by 陈志明 on 2021/8/25.
//

/*
 * 考点：链表 + 滑动窗口指针
 * 难度：**
 * */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        ListNode *p = newHead, *q = newHead;
        //q先移动n步；
        while(n != 0 && q != NULL){
            q = q->next;
            n--;
        }

        //找到待删除的前一个结点；
        while(q->next != NULL){
            q = q->next;
            p = p->next;
        }

        //删除结点；
        ListNode *s = p->next;
        p->next = s->next;
        delete s;

        return newHead->next;
    }
};