/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> stA, stB;
        ListNode *p = headA; ListNode *q = headB;
        while(p != NULL) {
            stA.push(p);
            p = p->next;
        }
        while(q != NULL) {
            stB.push(q);
            q = q->next;
        }

        ListNode *x = NULL;
        while(!stA.empty() && !stB.empty() && stA.top() == stB.top()) {
            x = stA.top();
            stA.pop();
            stB.pop();
        }

        return x;
    }
};