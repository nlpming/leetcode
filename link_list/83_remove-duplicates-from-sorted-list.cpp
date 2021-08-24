//
// Created by 陈志明 on 2021/8/24.
//

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head, *next;

        //NOTE: 注意三个连续一样值的情况（例如：[1,1,1]）；
        while(cur){
            if(cur->next != NULL && cur->val == cur->next->val){
                next = cur->next;
                cur->next = next->next; //NOTE: 删除结点后，不应该将cur指向cur->next，需要再次判断；
                delete next;
            }else{
                cur = cur->next;
            }
        }

        return head;
    }
};