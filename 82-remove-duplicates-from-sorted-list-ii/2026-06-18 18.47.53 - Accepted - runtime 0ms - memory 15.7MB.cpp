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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL) return head;
        ListNode *p = head, *q = head->next, *r = NULL;

        while(q!= NULL) {
            if(p->val != q->val) {
                r = p;
                p = p->next;
                q= q->next;
            }
            else {
                while(q && p->val == q->val) q = q->next;
                if(r == NULL) head = q;
                else r->next = q;
                p = q;
                if(q) q = q->next;
            }
        }

        return head;
    }
};