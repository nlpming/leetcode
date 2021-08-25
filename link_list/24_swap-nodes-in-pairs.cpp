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
        ListNode *new_head = new ListNode(0);
        new_head->next = head;

        //NOTE：rear指向左边链表的最后一个；p指向右边断开链表的第一个；
        ListNode *cur = head, *next, *p, *rear = new_head;

        while(cur != NULL){
            next = cur->next;
            if(next != NULL){ //NOTE: 注意每一次都需判断指针是否为NULL；
                p = next->next;
                rear->next = next;
                next->next = cur;

                rear = cur;
                rear->next = NULL;
                cur = p;
            }else{
                rear->next = cur;
                cur = cur->next;
            }
        }

        return new_head->next;
    }
};