//
// Created by 陈志明 on 2020/5/17.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：对链表进行插入排序
 * 考点：插入排序，链表
 * 是否做出：否
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        while(head && head->next){
            // 有序，直接后移
            if(head->val < head->next->val){
                head = head->next;
                continue;
            }

            // 找到插入点
            ListNode *pre = dummyHead;
            while(pre->next->val < head->next->val)
                pre = pre->next;

            // 插入新的结点
            ListNode *s = head->next;
            head->next = s->next;
            s->next = pre->next;
            pre->next = s;
        }
        head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};

int main() {
    vector<int> nums = {4,2,1,3};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().insertionSortList(head);
    printLinkList(head);


    return 0;
}