//
// Created by 陈志明 on 2021/8/25.
//

/*
 * 考点：链表 + 滑动窗口；
 * 难度：***
 * */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *new_head = new ListNode(0);

        ListNode *cur = head, *next, *p = head, *q = NULL, *rear = new_head;
        int idx = 1;

        while(p != NULL){
            //NOTE: p指针先移动k个位置；
            while(idx%k != 0 && p != NULL){
                p = p->next;
                idx++;
            }

            //NOTE: 不构成k组；
            if(p == NULL){
                if(q != NULL){
                    rear->next = q;
                }
                break;
            }

            q = p->next; //q指向p的下一个位置；

            //NOTE: 反转的k个元素插入链表中；【每次插入在头结点之后，就变成一个逆序了】
            while(cur != q){
                next = cur->next;

                cur->next = rear->next;
                rear->next = cur;
                cur = next;
            }

            //NOTE: rear移动到最后一个位置；
            while(rear->next != NULL){
                rear = rear->next;
            }

            p = q;
            cur= q;
            idx++;
        }

        return new_head->next;
    }
};