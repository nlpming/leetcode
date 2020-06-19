//
// Created by 陈志明 on 2020/5/18.
//
#include <iostream>
#include <vector>
#include "link_list.h"
using namespace std;

/**
 * 题目描述：旋转链表
 * 考点：链表，双指针、循环链表
 * 是否做出：否
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
            return head;

        ListNode *cur = head;
        ListNode *tail;

        // 获取链表长度
        int length = 1;
        while(cur->next != NULL){
            cur = cur->next;
            length += 1;
        }

        int loop = length-(k%length); //得到循环的次数
        tail = cur;

        // 得到循环链表
        cur->next = head;
        cur = head;

        // 开始循环
        for(int i=0; i<loop; i++){
            cur = cur->next;
            tail = tail->next;
        }
        tail->next = NULL;
        return cur;

    }
};


int main() {
    vector<int> nums = {1,2,3,4,5};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().rotateRight(head, 2);
    printLinkList(head);

    return 0;
}