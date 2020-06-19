//
// Created by 陈志明 on 2020/5/23.
//
#include <iostream>
#include <vector>
#include <queue>
#include "link_list.h"
using namespace std;

/**
 * 题目描述：合并k个排序链表
 * 考点：堆、链表
 * 是否做出：是
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 建立最小堆
        priority_queue<int, vector<int>, greater<int>> heap;

        // 链表入堆
        for(int i = 0; i < lists.size(); i++){
            ListNode *head = lists[i];
            while(head){
                heap.push(head->val);
                head = head->next;
            }
        }

        ListNode *dummyHead = new ListNode(0);
        ListNode *r = dummyHead;
        // 输出结果
        while(!heap.empty()){
            ListNode *s = new ListNode(heap.top());
            r->next = s;
            r = s;
            heap.pop();
        }

        ListNode *head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};


int main() {


    return 0;
}