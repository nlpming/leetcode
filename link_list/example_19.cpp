//
// Created by 陈志明 on 2020/5/18.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：删除链表的倒数第n个结点
 * 考点：链表、双指针
 * 是否做出：是
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead, *q = dummyHead;

        // q与p相隔n个位置
        while(n > 0 && q->next){
            n--;
            q = q->next;
        }

        // 找到删除的倒数第n个结点，前一个结点
        while(q->next){
            p = p->next;
            q = q->next;
        }

        ListNode *s = p->next;
        p->next = s->next;
        delete s;

        head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().removeNthFromEnd(head, 5);
    printLinkList(head);

    return 0;
}