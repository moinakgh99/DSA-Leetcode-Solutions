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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *p = head;
        vector<int> nodes;
        while(p != NULL) {
            nodes.push_back(p->val);
            p = p->next;
        }

        if(nodes.size() <= 2) return {-1, -1};

        vector<int> distance;
        for(int i = 1; i < nodes.size(); i++) {
            if(nodes[i] < nodes[i-1] && nodes[i] < nodes[i+1]) distance.push_back(i);
            else if(nodes[i] > nodes[i-1] && nodes[i] > nodes[i+1]) {
                distance.push_back(i);
            }
        }

        vector<int> res;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 1; i < distance.size(); i++) {
            mini = min(mini,abs(distance[i-1] - distance[i]));
            maxi = max(mini,abs(distance[i-1] - distance[i]));
        }

        res.push_back(mini);
        res.push_back(maxi);
        return res;
    }
};