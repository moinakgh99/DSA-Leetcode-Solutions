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
        while(p != NULL) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
        return q;
    }

    bool isPalindrome(ListNode* head) {
        
        // Using vector
        // vector<int> res;
        // ListNode *p = head;
        // while(p != NULL) {
        //     res.push_back(p->val);
        //     p = p->next;
        // }

        // int i = 0, j = res.size() - 1;
        // while(i <= j) {
        //     if(res[i] != res[j]) {
        //         return false;
        //     }
        //     i++; j--;
        // }
        // return true;

        // Doing in O(1) space;
        ListNode *p = head, *q = head;
        if(head == NULL || head->next == NULL) return true;
        while(q != NULL && q->next != NULL) {
            p = p->next;
            q = q->next->next;
        }
        
        ListNode *reversing = reverseLL(p);

        ListNode *x = head;
        ListNode *y = reversing;

        while(y != NULL) {
            if(x->val != y->val) return false;
            x = x->next;
            y = y->next;
        }
        return true;
    }
};