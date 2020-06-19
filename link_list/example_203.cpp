//
// Created by 陈志明 on 2020/5/16.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：移除链表元素
 * 考点：链表
 * 是否做出：是
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 添加一个虚拟头结点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        head = dummyHead;

        while(head->next){
            if(head->next->val == val){
                ListNode *s = head->next;
                head->next = s->next;
                delete s;
            }
            else{
                head = head->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};


int main(){
    vector<int> nums = {1,2,6,3,4,5,6};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().removeElements(head, 6);
    printLinkList(head);


    return 0;
}
