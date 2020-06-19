//
// Created by 陈志明 on 2020/5/16.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：合并两个有序链表
 * 考点：链表
 * 是否做出：是
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *r = head;
        ListNode *p = l1, *q = l2;

        while(p && q){
            if(p->val <= q->val){
                r->next = p;
                r = p;
                p = p->next;
            }
            else{
                r->next = q;
                r = q;
                q = q->next;
            }
        }

        while(p){
            r->next = p;
            r = p;
            p = p->next;
        }

        while(q){
            r->next = q;
            r = q;
            q = q->next;
        }

        r->next = NULL;
        return head->next;
    }
};


int main(){
    vector<int> nums1 = {1,2,4};
    vector<int> nums2 = {1,3,4};

    ListNode *l1 = createLinkList(nums1);
    ListNode *l2 = createLinkList(nums2);
    printLinkList(l1);
    printLinkList(l2);

    ListNode *head;
    head = Solution().mergeTwoLists(l1, l2);
    printLinkList(head);

    return 0;
}