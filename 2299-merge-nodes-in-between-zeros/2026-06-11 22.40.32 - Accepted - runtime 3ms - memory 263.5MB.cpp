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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p = head->next;
        ListNode *q = head->next;
        int sum = 0;

        while(q != NULL) {
            if(q->val != 0) {
                sum += q->val;
            } else {
                p->val = sum;
                if(q->next != NULL) {
                    p->next = q->next;
                    p = p->next;
                }
                sum = 0;
            }
            q = q->next;
        }
        p->next = NULL;

        return head->next;
    }
};