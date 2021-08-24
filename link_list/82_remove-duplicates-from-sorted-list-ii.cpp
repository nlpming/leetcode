//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表 + 查找表
 * 难度：**
 * */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *cur = new_head, *next;

        unordered_set<int> record;
        while(cur->next != NULL){
            next = cur->next;

            //NOTE: 是否在待删除的集合中；
            if(record.find(next->val) != record.end()){
                cur->next = next->next;
                delete next;
            }else{
                //NOTE: 检查是否存在重复，如果有重复则放入set中；
                if(next->next != NULL && next->val == next->next->val){
                    if(record.find(next->val) == record.end()){
                        record.insert(next->val);
                    }
                }else{
                    cur = cur->next;
                }
            }
        }

        return new_head->next;
    }
};