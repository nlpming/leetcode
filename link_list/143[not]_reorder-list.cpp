//
// Created by 陈志明 on 2021/8/25.
//

#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/*
 * 考点：快慢指针 + 链表反转
 * 难度：***
 * */
class Solution {
public:
    ListNode *reverseList(ListNode *head){
        ListNode *new_head = new ListNode(0);

        ListNode *cur = head, *next, *rear = new_head;
        while(cur != NULL){
            next = cur->next;
            cur->next = rear->next;
            rear->next = cur;

            cur = next;
        }

        return new_head->next;
    }

    void reorderList(ListNode* head) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;

        ListNode *slow = new_head, *fast = new_head, *rear = new_head;
        //NOTE: 1.快慢指针找到中间结点；
        while(fast != NULL){
            slow = slow->next;
            if(fast->next != NULL)
                fast = fast->next->next;
            else
                fast = fast->next;
        }

        //NOTE: 2.链表拆分成left, right；
        ListNode *pre = new_head;
        while(pre->next != slow){
            pre = pre->next;
        }
        pre->next = NULL;

        //NOTE: 3.right部分进行反转；
        ListNode *right = reverseList(slow);
        ListNode *left = new_head->next;

        //NOTE: 4.遍历left, right链表生成新链表
        while(left != NULL || right != NULL){
            if(left != NULL){
                rear->next = left;
                rear = left;
                left = left->next;
            }

            if(right != NULL){
                rear->next = right;
                rear = right;
                right = right->next;
            }
        }
    }
};


int main(){

    Solution s;
    ListNode *head;
    vector<int> nums = {3,0,4,2};
    head = createLinkList(nums);
    printLinkList(head);

    s.reorderList(head);
    printLinkList(head);

    return 0;
}




