//
// Created by 陈志明 on 2021/8/24.
//

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //NOTE: 增加虚拟头结点；
        ListNode *new_head = new ListNode(0);
        new_head->next = head;

        ListNode *cur = new_head, *next;
        while(cur->next != NULL){ //NOTE: 注意此处判断条件；
            next = cur->next;
            if(next->val == val){ //NOTE: 删除结点后还需要验证；所以不需要执行：cur = cur->next;
                cur->next = next->next;
                delete next;
            }else{
                cur = cur->next;
            }
        }

        return new_head->next;
    }
};