//
// Created by 陈志明 on 2021/11/10.
//
#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;

/*
 * 考点：归并排序 + 链表；
 * 难度：****
 * */
class Solution {
public:
    ListNode* mergeList(ListNode *left, ListNode *right){
        ListNode *newHead = new ListNode(0), *rear = newHead;
        ListNode *flag = right; //记录left终点位置，即right起点位置；

        while(left != flag || right != NULL){
            if(left == flag){
                rear->next = right;
                rear = right;
                right = right->next;
            }else if(right == NULL){
                rear->next = left;
                rear= left;
                left = left->next;
            }else{
                if(left->val < right->val){
                    rear->next = left;
                    rear= left;
                    left = left->next;
                }else{
                    rear->next = right;
                    rear = right;
                    right = right->next;
                }
            }
        }

        rear->next = NULL; //末尾指针置为NULL；
        ListNode *returnNode = newHead->next;
        delete newHead;

        return returnNode;
    }

    ListNode* sortList(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        //获取链表长度；
        int length = 0;
        ListNode *p = newHead;
        while(p->next != NULL){
            length++;
            p = p->next;
        }

        //解题思路：
        //1. 每次取size个元素进行排序；【left: size个, right: size个】
        //2. 这size个元素已经排序好了；

        for(int size = 1; size <= length; size *= 2){
            ListNode *rear = newHead;
            ListNode *cur = newHead->next, *pre;

            while(cur != NULL){
                ListNode *left = cur;
                ListNode *right = cur;

                //（1）移动cur；并切分链表；
                int tmp = 2*size;
                while(tmp != 0 && cur != NULL){
                    tmp--;
                    pre = cur;
                    cur = cur->next;
                }
                pre->next = NULL;

                //（2）移动right到中间位置；
                tmp = 0;
                while(tmp < size && right != NULL){
                    tmp++;
                    right = right->next;
                }

                //（3）合并排序链表；
                ListNode *node = mergeList(left, right);

                //（4）串联链表；
                while(node != NULL){
                    rear->next = node;
                    rear = node;
                    node = node->next;
                }
            }
        }

        head = newHead->next;
        delete newHead;
        return head;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,3,5,6,4};
    ListNode *head = createLinkList(nums);

    printLinkList(head);
    ListNode *newHead = s.sortList(head);
    printLinkList(newHead);

    return 0;
}

