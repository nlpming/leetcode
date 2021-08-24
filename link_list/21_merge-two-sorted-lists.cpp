//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表 + 一次归并排序
 * */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *rear = head;
        ListNode *p = l1, *q = l2;

        while(p != NULL && q != NULL){
            if(p->val < q->val){
                rear->next = p;
                rear = p;
                p = p->next;
            }else{
                rear->next = q;
                rear = q;
                q = q->next;
            }
        }

        while(p != NULL){
            rear->next = p;
            rear = p;
            p = p->next;
        }

        while(q != NULL){
            rear->next = q;
            rear = q;
            q = q->next;
        }

        return head->next;
    }
};