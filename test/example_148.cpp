//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

class Solution {
private:
    /*
     * 当前结点之后的n结点切掉，返回后面链表指针；
     */
    ListNode* cut(ListNode *head, int n){
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead;

        while(n && p->next){
            n--;
            p = p->next;
        }

        ListNode *next = p->next;
        p->next = NULL;
        delete dummyHead;

        return next;
    }

    ListNode* merge(ListNode *left, ListNode *right){
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;

        while(left && right){
            if(left->val <= right->val){
                cur->next = left;
                cur = left;
                left = left->next;
            }
            else{
                cur->next = right;
                cur = right;
                right = right->next;
            }
        }

        while(left){
            cur->next = left;
            left = left->next;
        }

        while(right){
            cur->next = right;
            right = right->next;
        }

        ListNode *head = dummyHead->next;
        delete dummyHead;
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = head;

        // 获取链表长度
        int length = 0;
        while(p){
            p = p->next;
            length += 1;
        }

        for(int size = 1; size < length; size *= 2){
            ListNode *cur = dummyHead->next;
            ListNode *tail = dummyHead;

            while(cur){
                ListNode *left = cur;
                ListNode *right = cut(left, size);
                cur = cut(right, size); // 更新位置

                tail->next = merge(left, right);
                while(tail->next)
                    tail = tail->next;


            }
        }

        return dummyHead->next;
    }
};

int main() {
    vector<int> nums = {4,2,1,3};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    head = Solution().sortList(head);
    cout<<"最终输出："<<endl;
    printLinkList(head);

    return 0;
}



