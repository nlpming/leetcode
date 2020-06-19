//
// Created by 陈志明 on 2020/5/16.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：两数相加
 * 考点：链表
 * 是否做出：是
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL)
            return NULL;

        ListNode *head = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *r = head;

        int remain = 0;
        while(p1 || p2){
            int p1_val = p1 != NULL ? p1->val : 0;
            int p2_val = p2 != NULL ? p2->val : 0;
            int sum_val = p1_val + p2_val + remain;

            // 插入新结点
            int val = sum_val%10;
            ListNode *s = new ListNode(val);
            r->next = s;
            r = s;
            remain = sum_val/10;

            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }

        // 注意余数不为0的情况
        if(remain != 0){
            ListNode *s = new ListNode(remain);
            r->next = s;
        }

        return head->next;
    }
};


int main(){
    vector<int> nums1={2,4,3,1};
    ListNode *l1 = createLinkList(nums1);

    vector<int> nums2={5,6,4};
    ListNode *l2 = createLinkList(nums2);

    printLinkList(l1);
    printLinkList(l2);

    ListNode *head;
    head = Solution().addTwoNumbers(l1, l2);
    printLinkList(head);

    return 0;
}

