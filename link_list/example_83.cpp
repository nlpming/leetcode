//
// Created by 陈志明 on 2020/5/16.
//
#include <iostream>
#include <vector>
#include "link_list.h"
using namespace std;

/**
 * 题目描述：删除排序链表中的重复元素
 * 考点：链表
 * 是否做出：是
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 注意：链表为空的情况
        if(head == NULL)
            return NULL;

        ListNode* p = head, *q;
        while(p->next){
            if(p->val == p->next->val){
                q = p->next;
                p->next = q->next;
                delete q;
            }
            else{
                p = p->next;
            }
        }

        return head;
    }
};

int main(){
    vector<int> nums = {1,1,2,3,3};
    ListNode* head;

    head = createLinkList(nums);
    printLinkList(head);

    head = Solution().deleteDuplicates(head);
    printLinkList(head);


    return 0;
}
