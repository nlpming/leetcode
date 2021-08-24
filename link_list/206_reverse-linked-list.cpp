//
// Created by 陈志明 on 2021/8/24.
//

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *cur = head, *pre = NULL, *next;

        //解题思路：
        // 1. cur指向当前要处理的元素；pre前一个元素的指针；next下一个元素的指针；
        // 2. 迭代过程：结束条件为cur为NULL；
        //（1）获取当前元素下一个元素：next = cur->next;
        //（2）cur->next = pre; pre = cur;
        //（3）cur = next;

        while(cur){
            next = cur->next;

            cur->next = pre;
            pre = cur;

            cur = next;
        }

        return pre;
    }
};