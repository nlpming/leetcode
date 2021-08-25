//
// Created by 陈志明 on 2021/8/24.
//

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *cur = head, *pre = NULL, *next;

        //解题思路1：
        // 1. cur指向当前要处理的元素；pre前一个元素的指针；next下一个元素的指针；
        // 2. 迭代过程：结束条件为cur为NULL；
        //（1）获取当前元素下一个元素：next = cur->next;
        //（2）cur->next = pre; pre = cur;
        //（3）cur = next;

        //解题思路2：
        // 1. cur,next两个指针记录当前元素，和下一个元素；
        // 2. 每次把当前元素插入到头结点的下一个结点，即可实现逆序；【新建链表类似过程】

        while(cur){
            next = cur->next;

            cur->next = pre;
            pre = cur;

            cur = next;
        }

        return pre;
    }
};