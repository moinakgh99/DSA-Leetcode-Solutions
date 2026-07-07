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
    int pairSum(ListNode* head) {
        ListNode *p = head;
        vector<int> res;
        while(p != NULL) {
            res.push_back(p->val);
            p = p->next;
        }

        int n = res.size();
        int maxi = INT_MIN;
        for(int i = 0; i <= (n/2) - 1; i++) {
            int j = n - 1 - i;
            maxi = max(maxi, res[i] + res[j]);
        }

        return maxi;
    }
};