//
// Created by 陈志明 on 2021/11/5.
//
#include <iostream>
#include <vector>
#include "link_list.h"

/*
 * 考点：反转链表
 * 难度：***
 * */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode(0), *rear = newHead;
        ListNode *cur = head, *p, *q = head;

        while(q != NULL){
            //q向前移动k步；
            int n = k;
            while(n != 0 && q != NULL){
                n--;
                q = q->next;
            }

            //NOTE: 剩余不足k个结点；
            if(q == NULL && n != 0){
                rear->next = cur;
                break;
            }

            //反转cur -> q之前的结点；
            ListNode *tmpHead = new ListNode(0), *tmpRear = tmpHead;
            while(cur != q){
                p = cur->next;

                cur->next = tmpRear->next;
                tmpRear->next = cur;

                cur = p;
            }

            //rear串联整个链表；
            rear->next = tmpHead->next;
            while(rear->next != NULL)
                rear = rear->next;

            delete tmpHead;
            cur = q;
        }

        return newHead->next;
    }
};

int main(){

    Solution s;

    vector<int> nums = {1,2,3,4,5};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    ListNode *newHead = s.reverseKGroup(head, 3);
    printLinkList(newHead);

    return 0;
}




