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
    ListNode* sortList(ListNode* head) {

        // Using Space
        if(head == NULL) return NULL;
        ListNode *p = head;
        vector<int> arr;

        while(p != NULL) {
            arr.push_back(p->val);
            p = p->next;
        }

        p = head;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; i++) {
            p->val = arr[i];
            p = p->next;
        }

        return head;
    }
};