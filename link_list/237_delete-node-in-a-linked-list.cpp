//
// Created by 陈志明 on 2021/8/25.
//

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next;

        if(node->next != NULL){
            next = node->next;
            //NOTE: 下一个结点的值，赋值给当前结点；
            node->val = next->val;

            //NOTE: 删除下一个结点；
            node->next = next->next;
            delete next;
        }
    }
};