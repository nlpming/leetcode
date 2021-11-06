//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：链表
 * 难度：**
 * */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *cur = head, *next, *p;

        //NOTE: 增加两个头结点odd, even；并建立 odd->next = even 这样的关系；
        ListNode *odd = new ListNode(0);
        head = odd;
        ListNode *even = new ListNode(0);
        odd->next = even;

        while(cur != NULL){
            next = cur->next;

            if(next != NULL){
                p = next->next;

                //偶数index处理
                next->next = even->next;
                even->next = next;
                even = next;

                //奇数index处理；
                cur->next = odd->next;
                odd->next = cur;
                odd = cur;

                cur = p;
            }else{
                //NOTE: 多一个奇数的情况；
                cur->next = odd->next;
                odd->next = cur;
                odd = cur;
                break;
            }
        }

        if(odd->next != NULL){
            ListNode *s = odd->next;
            odd->next = odd->next->next;
            delete s;
        }

        return head->next;
    }
};

