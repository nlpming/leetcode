//
// Created by 陈志明 on 2020/5/15.
//

#include <iostream>
#include <vector>
#include "link_list.h"

/**
 * 题目描述：反转链表
 * 考点：链表
 * 是否做出：是
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 注意链表为空的情况
        if(head == NULL)
            return NULL;

        ListNode* p = NULL;
        ListNode* q = head;
        while(head->next){
            head = head->next;
            q->next = p;
            p = q;
            q = head;
        }
        head->next = p;

        return head;
    }
};


int main(){
    vector<int> nums={1, 3, 4, 5};
    ListNode* head = createLinkList(nums);

    printLinkList(head);
    head = Solution().reverseList(head);
    printLinkList(head);

    return 0;
}


