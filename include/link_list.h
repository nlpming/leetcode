//
// Created by 陈志明 on 2020/5/15.
//

#ifndef WORKSPACE_LINKLIST_H
#define WORKSPACE_LINKLIST_H


#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 创建链表，没有头结点
 * @param nums
 * @return
 */
ListNode* createLinkList(vector<int> nums){
    assert(nums.size() > 0);
    ListNode *head = new ListNode(nums[0]);
    ListNode *p = head;

    for(int i=1; i<nums.size(); i++){
        ListNode* s = new ListNode(nums[i]);
        p->next = s;
        p = s;
    }
    return head;
}

/**
 * 打印链表
 * @param head
 */
void printLinkList(ListNode* head){
    while(head){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}


#endif //WORKSPACE_LINKLIST_H
