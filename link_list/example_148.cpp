//
// Created by 陈志明 on 2020/5/18.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：排序链表，时间复杂度O(nlogn)，空间复杂度O(1)
 * 考点：链表，归并排序
 * 是否做出：否
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = head;
        int length = 0;

        // 获得链表长度
        while (p) {
            ++length; p = p->next;
        }

        for (int size = 1; size < length; size *= 2) {
            ListNode *cur = dummyHead->next;
            ListNode *tail = dummyHead;

            while (cur) {
                ListNode *left = cur;
                ListNode *right = cut(left, size); // left->@->@ right->@->@->@...
                // cur指向后续需要归并的链表头指针
                cur = cut(right, size); // left->@->@ right->@->@  cur->@->...

                // 二路归并排序，tail将断开的链表串起来
                tail->next = merge(left, right);

                // 保持tail为尾部
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }

        return dummyHead->next;
    }

    /**
     * 将head之后n个结点切掉，返回后面的链表
     * @param head
     * @param n
     * @return
     */
    ListNode* cut(ListNode* head, int n) {
        ListNode *p = head;
        while (--n && p) {
            p = p->next;
        }

        if (!p) return NULL;

        ListNode *next = p->next;
        p->next = NULL;
        return next;
    }

    /**
     * 二路归并排序
     * @param l1
     * @param l2
     * @return
     */
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *p = dummyHead;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        // 注意此处
        p->next = l1 ? l1 : l2;
        return dummyHead->next;
    }
};

int main() {
    vector<int> nums = {4,2,1,3};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().sortList(head);
    printLinkList(head);

    return 0;
}