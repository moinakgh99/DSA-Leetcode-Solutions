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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL and head->val == val) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        if(head == NULL) return head;   

        ListNode *q = NULL;
        ListNode *p = head;

        while( p != NULL) {
            if( p->val != val) {
                q = p;
                p = p->next;
            }
            else {
                q->next = p->next;
                delete p;
                p = q->next;
            }
        }
        return head;
    }
};