//
// Created by 陈志明 on 2020/5/18.
//
#include <iostream>
#include <vector>
#include "link_list.h"
using namespace std;

/**
 * 题目描述：删除链表中的结点
 * 考点：链表
 * 是否做出：是
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // 注意为末结点的情况
        if(node->next == NULL){
            node = NULL;
            return;
        }

        node->val = node->next->val;
        ListNode *s = node->next;
        node->next = s->next;
        delete s;
    }
};


int main() {
    vector<int> nums = {4,5,1,9};
    ListNode *head = createLinkList(nums);
    ListNode *node = head->next;

    printLinkList(head);
    cout<<node->val<<endl;
    Solution().deleteNode(node);
    printLinkList(head);

    return 0;
}