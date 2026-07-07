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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode(0);
        ListNode *large = new ListNode(1);

        ListNode *p = head;
        ListNode *a = small, *b = large;

        while(p != NULL) {
            if(p->val < x) {
                a->next = p;
                a = a->next;
            }
            else {
                b->next = p;
                b = b->next;
            }
            p = p->next;
        }

        b->next = NULL;
        a->next = large->next;

        return small->next;
    }
};