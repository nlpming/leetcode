//
// Created by 陈志明 on 2020/5/16.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：分隔链表
 * 考点：链表，双指针
 * 是否做出：否
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;

        // 新增两个带头结点的链表；
        ListNode *leftHead = new ListNode(0);
        ListNode *rightHead = new ListNode(0);
        ListNode *left = leftHead, *right = rightHead;

        while(head){
            if(head->val >= x){
                right->next = head;
                right = head;
            }
            else{
                left->next = head;
                left = head;
            }
            head = head->next;
        }

        left->next = rightHead->next;
        right->next = NULL;
        return leftHead->next;
    }
};

int main(){
    vector<int> nums = {1,4,3,2,5,2};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().partition(head, 3);
    printLinkList(head);

    return 0;
}
