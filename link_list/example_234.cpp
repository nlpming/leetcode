//
// Created by 陈志明 on 2020/5/18.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：回文链表
 * 考点：链表，双指针
 * 是否做出：否
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head,  *prev = nullptr;

        // 找到中间结点
        while(fast){
            slow = slow->next;
            fast = fast->next ? fast->next->next: fast->next;
        }

        // 后半部分逆序
        while(slow){
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // 判断是否为回文链表
        while(head && prev){
            if (head->val != prev->val){
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};


int main() {
    vector<int> nums = {1,2,2,1};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    cout<<Solution().isPalindrome(head)<<endl;

    return 0;
}