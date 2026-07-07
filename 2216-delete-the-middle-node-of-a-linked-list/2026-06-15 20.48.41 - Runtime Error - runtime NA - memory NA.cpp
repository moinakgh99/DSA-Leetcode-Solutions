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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *r = NULL, *p = head, *q = head;
        if(head == NULL || head->next == NULL) {
            delete p;
            head = NULL;
            return head;
        }

        while(q != NULL && q->next != NULL) {
            r = p;
            p = p->next;
            q = q->next->next;
        }
        r->next = p->next;
        delete(p);

        return head; 
    }
};