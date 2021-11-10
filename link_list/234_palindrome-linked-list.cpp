//
// Created by 陈志明 on 2021/8/26.
//

/*
 * 考点：快慢指针 + 反转链表
 * 难度：***
 * */
class Solution {
public:
    ListNode *reverseList(ListNode *head){
        ListNode *cur = head, *pre = NULL, *next;
        while(cur != NULL){
            next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        //快慢指针，二分链表；
        ListNode *slow = newHead, *fast = newHead, *pre;
        while(fast != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
        }
        pre->next = NULL;

        //链表逆序；
        ListNode *left = head;
        ListNode *right = reverseList(slow);

        //判断是否为回文链表；【注意字符串个数为，奇数或者偶数的情况】
        while(left != NULL && right != NULL){
            if(left->val == right->val){
                left = left->next;
                right = right->next;
            }else{
                return false;
            }
        }

        return true;
    }
};