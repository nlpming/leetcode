//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：堆；
 * 难度：***
 * 题名：23.合并K个升序链表
 * */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //NOTE: 维护一个大小为K的最小堆；
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode *head = new ListNode(0), *rear=head;

        //1. K个头结点值入堆；
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL)
                pq.push(make_pair(lists[i]->val, lists[i]));
        }

        //2. 把堆中值最小的出堆，压入其下一个结点；
        while(!pq.empty()){
            ListNode *s = pq.top().second;
            pq.pop();

            rear->next = s;
            rear = s;

            //3. 下一个结点入堆；
            if(s->next != NULL){
                pq.push(make_pair(s->next->val, s->next));
            }
        }

        return head->next;
    }
};