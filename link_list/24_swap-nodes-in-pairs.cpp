//
// Created by 陈志明 on 2021/8/25.
//

/*
 * 考点：链表
 * 难度：**
 * */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = new ListNode(0); //新增一个头结点；
        newHead->next = head;

        ListNode *cur = newHead, *p, *q;
        while(cur->next != NULL && cur->next->next != NULL){
            p = cur->next; //修改p,q的值；
            q = p->next;

            cur->next = q; //交换结点；
            p->next = q->next;
            q->next = p;

            cur = p; //修改cur指针；
            if(cur == NULL) break;
        }

        return newHead->next;
    }
};