//
// Created by 陈志明 on 2020/5/18.
//
#include <iostream>
#include <vector>
#include "link_list.h"
using namespace std;

/**
 * 题目描述：重排链表
 * 考点：数组，链表
 * 是否做出：否
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL)
            return;

        vector<ListNode*> record;
        ListNode *cur = head;

        // 将链表存入数组中
        while(cur){
            record.push_back(cur);
            cur = cur->next;
        }

        int left = 0;
        int right = record.size()-1;
        while(left < right){
            record[left]->next = record[right];
            left++;
            record[right]->next = record[left];
            right--;
        }
        record[left]->next = NULL;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    Solution().reorderList(head);
    printLinkList(head);

    return 0;
}