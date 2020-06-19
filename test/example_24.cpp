//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include "link_list.h"


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *left = dummyHead;
        ListNode *cur = dummyHead->next;
        ListNode *right = cur->next;

        // 注意穿针引线顺序
        while(cur && right){
            cur->next = right->next;
            right->next = cur;
            left->next = right;

            left = cur;
            if(left)
                cur = left->next;
            if(left && left->next)
                right = left->next->next;
        }

        head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().swapPairs(head);
    printLinkList(head);


    return 0;
}



