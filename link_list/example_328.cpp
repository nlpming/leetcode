//
// Created by 陈志明 on 2020/5/16.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：奇偶链表
 * 考点：链表
 * 是否做出：否
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;

        // p1,p2分别指向奇数位置和偶数位置
        ListNode *point1 = head, *point2 = head->next;
        ListNode *p1 = point1, *p2 = point2;

        while(p2 && p2->next){
            p1->next = p1->next->next;
            p2->next = p2->next->next;

            p1 = p1->next;
            p2 = p2->next;
        }

        p1->next = point2;
        return point1;
    }
};


int main(){
    vector<int> nums = {1,2,3,4,5};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().oddEvenList(head);
    printLinkList(head);

    return 0;
}