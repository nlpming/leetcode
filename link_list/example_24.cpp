//
// Created by 陈志明 on 2020/5/16.
//
#include <iostream>
#include <vector>
#include "link_list.h"
using namespace std;

/**
 * 题目描述：两两交换链表中的结点；
 * 考点：链表
 * 是否做出：是
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *front = dummyHead;
        ListNode *p = dummyHead->next;
        ListNode *q = p->next;

        while(front->next && front->next->next){
            p->next = q->next;
            q->next = p;
            front->next = q;

            // 注意下面的判断
            front = p;
            if(front->next)
                p = p->next;
            if(front->next && front->next->next)
                q = p->next;
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