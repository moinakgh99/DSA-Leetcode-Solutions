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
        ListNode *p = head, *r= NULL, *q = NULL;
        while(p != NULL) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }    
        return q;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if(head == NULL) return NULL;
        // if(head->next == NULL) return head;

        // ListNode *p = head, *q = NULL;
        // for(int i = 1; i <= left - 1; i++) {
        //     q = p;
        //     p = p->next;
        // }
        // if(q) q->next = NULL;
        // ListNode *r = p;
        // for(int i = left; i < right; i++) {
        //     r = r->next;
        // }

        // ListNode *s = r->next;
        // r->next = NULL;

        // r = p;
        // p = reverseLL(p);

        // if(q) q->next = p;
        // else head = p;
        // r->next = s;

        // return head;


        // One pass
        if(head == NULL) return NULL;
        if(left == right) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *q = dummy;
        for(int i = 1; i < left; i++) {
            q = q->next;
        }

        ListNode *p = q->next;
        for(int i = 1; i <= right - left; i++) {
            ListNode *temp = p->next;

            p->next = temp->next;
            temp->next = q->next;
            q->next = temp;
        }

        return dummy->next;
    }


};