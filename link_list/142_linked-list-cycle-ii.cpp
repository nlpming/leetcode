//
// Created by 陈志明 on 2021/10/24.
//

/*
 * 考点：快慢指针；
 * 难度：***
 * */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;

        //注意：
        //1. slow,fast交汇点距离，环形入口的距离c；等于链表开始结点距离环形入口的距离a；
        //2. fast指针走过的距离为：a + n(b+c) + b;
        //3. 满足关系：a + n(b+c) + b = 2(a+b) => n(b+c) = a+b => (n-1)(b+c) + c = a;
        //4. 从上述推导式，可以看出：a = c;

        ListNode *slow = head, *fast = head;
        //1. slow,fast交汇的地方
        while(slow != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            //不存在环【NOTE: 注意此处的判断】
            if(fast == NULL || fast->next == NULL)
                return NULL;
            if(slow == fast)
                break;
        }

        //2. 找到环形入口
        ListNode *p = head;
        while(p != fast){
            p = p->next;
            fast = fast->next;
        }

        return p;
    }
};