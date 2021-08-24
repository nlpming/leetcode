//
// Created by 陈志明 on 2021/8/24.
//

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == NULL) return head;
        ListNode *cur = head, *rear, *pre = NULL, *next;

        //新增一个头结点；NOTE: 从第一个元素就开始反转；
        rear = new ListNode(0);
        head = rear;
        rear->next = cur;

        int index = 1;
        while(cur){
            // NOTE: 需要反转的区域；
            if(index >= left && index <= right){
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;

                index++;
            }else{
                if(index < left){
                    rear = cur;
                    cur = cur->next;
                    index++;
                }else{
                    //NOTE: rear记录反转前的，最后一个元素；
                    rear->next = pre;
                    while(rear->next) rear = rear->next;
                    rear->next = cur;

                    break;
                }
            }
        }

        // NOTE：注意cur为空的情况【反转直到最后一个元素】
        if(rear->next != cur){
            rear->next = pre;
        }

        return head->next;
    }
};