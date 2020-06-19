//
// Created by 陈志明 on 2020/5/15.
//
#include <iostream>
#include <cassert>
#include <vector>
#include "print.h"
#include "link_list.h"

using namespace std;
/**
 * 题目描述：反转链表II
 * 考点：链表
 * 是否做出：是
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // NOTE: 1<= m <= n <= 链表长度
        assert(m >=1 && m <= n);
        vector<int> nums;
        ListNode* p = head, *q = head;
        int index = 1;

        // 找到要反转的区间，并存入vector
        while(q){
            if(index > n)
                break;

            if(index >= m && index <= n){
                nums.push_back(q->val);
                q = q->next;
            }
            else{
                p = p->next;
                q = q->next;
            }
            index += 1;
        }

        // 通过改变结点的值反转链表；
        int i = nums.size()-1;
        while(p != q){
            p->val = nums[i];
            p = p->next;
            i--;
        }

        return head;
    }
};


int main(){
    vector<int> nums = {1,2,3,4,5};
    int m = 2, n = 4;
    ListNode* head;

    head = createLinkList(nums);
    printLinkList(head);

    head = Solution().reverseBetween(head, m, n);
    printLinkList(head);


    return 0;
}