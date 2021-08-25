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
        ListNode *new_head = new ListNode(0);
        ListNode *cur = head, *next, *rear = new_head;

        while(cur != NULL){
            next = cur->next;
            cur->next = rear->next;
            rear->next = cur;

            cur = next;
        }

        return new_head->next;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;

        //NOTE: 1.快慢指针找到中间位置；
        ListNode *slow = new_head, *fast = new_head;
        while(fast!= NULL){
            slow = slow->next;
            if(fast->next != NULL)
                fast = fast->next->next;
            else
                fast = fast->next;
        }

        //NOTE: 2.拆分链表
        ListNode *p = new_head;
        while(p->next != slow){
            p = p->next;
        }
        p->next = NULL;

        //3.反转链表
        ListNode *right = reverseList(slow);
        ListNode *left = new_head->next;

        //4.比较left,right中的结点值，判断是否回文链表；【right可能比left多一个结点，当为奇数个结点的时候】
        while(left != NULL && right != NULL){
            if(left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }
        return true;
    }
};