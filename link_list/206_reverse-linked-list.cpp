/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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