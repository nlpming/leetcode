//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表；
 * 难度：**
 * */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *rear = newHead;

        //找到要反转的前一个结点；
        int index = 0;
        while(left > 1 && rear != NULL){
            rear = rear->next;
            left--;
            index += 1;
        }

        ListNode *cur = rear->next, *p = NULL;
        index += 1;
        rear->next = NULL;

        //反转left -> right的结点；
        while(cur != NULL && index <= right){
            p = cur->next;

            cur->next = rear->next;
            rear->next = cur;
            cur = p;
            index += 1;
        }

        //拼接剩余链表；
        while(rear->next != NULL)
            rear = rear->next;
        rear->next = p;

        return newHead->next;
    }
};