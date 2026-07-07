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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode *p = head;
        int n = 0;
        while(p != NULL) {
            n++;
            p = p->next;
        }

        k = k % n;
        p = head;

        for(int i = 0; i < k; i++) {
            p = p->next;
        }
        ListNode *q = p->next;
        p->next = NULL;
        p = q;

        while(q->next != NULL) q = q->next;

        q->next = head;

        return p; 
    }
};