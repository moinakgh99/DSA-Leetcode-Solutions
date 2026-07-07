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

    ListNode *reverseLL(ListNode *head) {
        ListNode *p = head, *q = NULL, *r = NULL;
        if(head == NULL) return NULL;

        while(p != NULL) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    } 

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head->next == NULL) return NULL;
        head = reverseLL(head);
        ListNode *p = head;

        if(n == 1) {
            ListNode *temp = head;
            head = head->next;
            delete(temp);
            return reverseLL(head);
        }

        for(int i = 0; i < n - 2; i++) {
            p = p->next;
        }

        ListNode *q = p->next;
        p->next = q->next;
        delete(q);

        head = reverseLL(head);
        return head;
    }
};