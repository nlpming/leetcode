//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表 + 双指针；
 * 难度：**
 * */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        ListNode *p = newHead, *q, *s;
        while(p->next != NULL){
            q = p->next;

            //存在重复结点；
            if(q->next != NULL && p->next->val == q->next->val){
                while(q != NULL && q->val == p->next->val)
                    q = q->next;

                //删除重复结点；
                while(p->next != q){
                    s = p->next;
                    p->next = s->next;
                    delete s;
                }
            }else{
                p = p->next;
            }
        }

        return newHead->next;
    }
};