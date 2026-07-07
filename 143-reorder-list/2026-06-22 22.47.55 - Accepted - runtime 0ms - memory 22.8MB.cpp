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
        if(head == NULL) return NULL;

        ListNode *p = head, *q = NULL, *r = NULL;
        while(p != NULL) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        head = q;
        return q;
    }

    void reorderList(ListNode* head) {
        if(head == NULL) return;
        ListNode *p = head, *q = head->next;

        while(q != NULL && q->next != NULL) {
            p = p->next;
            q = q->next->next;
        }

        q = p->next;
        p->next = NULL;
        p = head;

        q = reverseLL(q);

        while(p != NULL && q != NULL) {
            ListNode *x = p->next, *y = q->next;
            p->next = q;
            q->next = x;

            p = x;
            q = y;
        }
    }
};