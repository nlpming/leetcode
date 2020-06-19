//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <cstdlib>
#include "link_list.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *pre = NULL;
        ListNode *next;

        while(head->next){
            next = head->next; // 步骤[1]
            head->next = pre; // 步骤[2]
            pre = head; // 步骤[3]
            head = next; // 步骤[4]
        }

        head->next = pre;
        return head;
    }
};




