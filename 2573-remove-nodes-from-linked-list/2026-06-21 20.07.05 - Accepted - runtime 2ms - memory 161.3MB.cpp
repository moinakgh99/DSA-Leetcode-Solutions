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


    ListNode* removeNodes(ListNode* head) {
        head = reverseLL(head);
        if(head == NULL) return NULL;

        ListNode *p = head, *q = NULL;

        int maxi = -1;
        while(p != NULL) {
            maxi = max(maxi, p->val);
            if(p->val < maxi) {
                q->next = p->next;
                p = p->next;
            }
            else {
                q = p;
                p = p->next;
            }
        }

        head = reverseLL(head);
        return head;
    }
};