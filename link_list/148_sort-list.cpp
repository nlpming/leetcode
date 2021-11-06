//
// Created by 陈志明 on 2021/8/25.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/*
 * 考点：链表 + 归并排序；
 * 难度：***
 * */
class Solution {
public:
    ListNode* mergeList(ListNode *left, ListNode *right, ListNode *nextCur){
        ListNode *head = new ListNode(0), *rear = head;
        ListNode *rightStart = right; //right指针开始移动的位置；

        while(left != rightStart && right != nextCur){
            if(left->val < right->val){
                rear->next = left;
                rear = left;
                left = left->next;
            }else{
                rear->next = right;
                rear = right;
                right = right->next;
            }
        }

        while(left != rightStart){
            rear->next = left;
            rear = left;
            left = left->next;
        }

        while(right != nextCur){
            rear->next = right;
            rear = right;
            right = right->next;
        }

        //NOTE: 断开连接；【用于将rear指针移动到末尾】
        rear->next = NULL;

        ListNode *res = head->next;
        delete head;
        return res;
    }

    ListNode* sortList(ListNode* head) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;

        ListNode *cur, *p = head, *rear, *left, *right, *res;
        int length = 0;

        //NOTE：获取链表长度【用于循环的终止】
        while(p != NULL){
            p = p->next;
            length++;
        }

        //NOTE: 注意此处的终止条件
        for(int step = 1; step < length; step = step*2){
            //NOTE: 注意此处，每次需要将cur, rear重置；
            cur = new_head->next;
            rear = new_head;

            while(cur != NULL){
                //NOTE: left指向要处理范围的开始位置，right指向要处理范围的中间位置；
                left = cur;
                right = cur;

                //cur移动到下一个要处理的结点；
                int cur_step = 2*step;
                while(cur_step > 0 && cur != NULL){
                    cur = cur->next;
                    cur_step--;
                }

                //right指针移动到合适位置；
                int right_step = step;
                while(right_step > 0 && right != NULL){
                    right = right->next;
                    right_step--;
                }

                //NOTE: 归并排序过程；
                res = mergeList(left, right, cur);

                //rear指针移动到末尾；
                rear->next = res;
                while(rear->next != NULL){
                    rear = rear->next;
                }
            }
        }

        return new_head->next;
    }
};

int main(){

    Solution s;
    ListNode *head;
    vector<int> nums = {3,0,4,2,5,6,3};
    head = createLinkList(nums);
    printLinkList(head);

    ListNode *res = s.sortList(head);
    printLinkList(res);

    return 0;
}









