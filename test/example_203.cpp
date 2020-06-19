//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include "link_list.h"


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;

        // 增加虚拟头结点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead;

        while(p->next){
            if(p->next->val == val){
                ListNode *s = p->next;
                p->next = s->next;

                delete s;
            }
            else{
                p = p->next;
            }
        }

        delete dummyHead;
        return head;
    }
};

int main(){
    vector<int> nums = {1,2,6,3,4,5,6};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().removeElements(head, 6);
    printLinkList(head);


    return 0;
}

