//
// Created by 陈志明 on 2020/5/16.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include "link_list.h"

using namespace std;

/**
 * 题目描述：删除排序链表中的重复元素II
 * 考点：链表，查找表
 * 是否做出：是
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        head = dummyHead;
        unordered_set<int> record;

        while(head->next && head->next->next){
            if(head->next->val == head->next->next->val){
                // 找到重复元素
                record.insert(head->next->val);
                while(head->next && record.find(head->next->val) != record.end()){
                    ListNode *s = head->next;
                    head->next = s->next;
                    delete s;
                }
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
    vector<int> nums = {1,2,3,3,4,4,5};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().deleteDuplicates(head);
    printLinkList(head);

    return 0;
}