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
            q ->next = r;
        }

        head = q;
        return q;
    }

    int pairSum(ListNode* head) {

        // Brute Force ...
        // ListNode *p = head;
        // vector<int> res;
        // while(p != NULL) {
        //     res.push_back(p->val);
        //     p = p->next;
        // }

        // int n = res.size();
        // int maxi = INT_MIN;
        // for(int i = 0; i <= (n/2) - 1; i++) {
        //     int j = n - 1 - i;
        //     maxi = max(maxi, res[i] + res[j]);
        // }

        // return maxi;


        // Optimal Approach ..
        ListNode *p = head, *q = head;
        while(q != NULL && q->next != NULL) {
            p = p->next;
            q = q->next->next;
        }

        ListNode *reversing = reverseLL(p);
        ListNode *x = head;

        int maxi = INT_MIN;
        while(reversing != NULL) {
            maxi = max(maxi, x->val + reversing->val);
            x = x->next;
            reversing = reversing->next;
        }
        return maxi;
    }
};