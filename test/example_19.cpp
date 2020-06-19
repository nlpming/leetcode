//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include "link_list.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n <= 0)
            return head;

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *left = dummyHead, *right = dummyHead;

        // 先移动right
        while(n && right->next){ // 注意此处：需要判断right->next不为NULL
            right = right->next;
            n--;
        }

        // 同时移动left, right
        while(right->next){
            left = left->next;
            right = right->next;
        }

        // 删除元素
        ListNode *s = left->next;
        left->next = s->next;
        delete s;

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main(){


    return 0;
}




