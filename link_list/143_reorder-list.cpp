//
// Created by 陈志明 on 2021/11/10.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/*
 * 考点：快慢指针 + 反转链表；
 * 难度：****
 * */
class Solution {
public:
    ListNode *reverseList(ListNode *head){
        ListNode *newHead = new ListNode(0);

        ListNode *cur = head, *next;
        while(cur != NULL){
            next = cur->next;

            cur->next = newHead->next;
            newHead->next = cur;
            cur = next;
        }

        return newHead->next;
    }

    void reorderList(ListNode* head) {
        ListNode *newHead = new ListNode(0), *rear = newHead;
        newHead->next = head;

        //快慢指针，二分链表；
        ListNode *pre, *slow = newHead, *fast = newHead;
        while(fast != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL) //注意快慢指针终止条件的写法；
                fast = fast->next;
        }
        pre->next = NULL;

        //反转链表；
        ListNode *left = newHead->next;
        ListNode *right = reverseList(slow);

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
    vector<int> nums = {1,2,3,4};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    s.reorderList(head);
    printLinkList(head);

    return 0;
}



