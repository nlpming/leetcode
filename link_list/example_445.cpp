//
// Created by 陈志明 on 2020/5/16.
//
#include <iostream>
#include <vector>
#include <stack>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：两数相加II
 * 考点：链表、栈
 * 是否做出：否
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stack1, stack2;
        ListNode *head = new ListNode(0);
        ListNode *r = head;

        // 将链表数据压入栈
        while(l1){
            stack1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            stack2.push(l2->val);
            l2 = l2->next;
        }

        int remain = 0;
        while(!stack1.empty() || !stack2.empty()){
            int p1_val = stack1.empty() ? 0 : stack1.top();
            if(!stack1.empty()) stack1.pop();
            int p2_val = stack2.empty() ? 0 : stack2.top();
            if(!stack2.empty()) stack2.pop();

            int sum_val = p1_val + p2_val + remain;
            ListNode *s = new ListNode(sum_val%10);
            s->next = r->next;
            r->next = s;
            remain = sum_val/10;
        }

        if(remain != 0){
            ListNode *s = new ListNode(remain);
            s->next = r->next;
            r->next = s;
        }

        return head->next;
    }
};

int main(){
    vector<int> nums1={7,2,4,3};
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