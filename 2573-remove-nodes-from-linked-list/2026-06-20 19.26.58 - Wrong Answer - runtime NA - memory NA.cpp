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
    ListNode* removeNodes(ListNode* head) {
        ListNode *p = head, *q = head->next;

        while(q != NULL) {
            if(q->val < p->val) {
                p = p->next;
                q = q->next;
            }
            else {
                if(q->val > p->val) {
                    head = q;
                    p = q;
                    q = q->next;
                }
                q = q->next;
            }
        }

        return head;
    }
};