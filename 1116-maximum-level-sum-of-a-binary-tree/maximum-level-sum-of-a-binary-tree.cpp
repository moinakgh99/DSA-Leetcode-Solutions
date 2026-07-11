/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;

        TreeNode *p = root;
        queue<TreeNode *> q;

        q.push(root);

        vector<long long> levels;
        while(!q.empty()) {
            int size = q.size();

            long long sum = 0;
            for(int i = 0; i < size; i++) {
                p = q.front();
                long long value = p->val;
                q.pop();

                sum += value;

                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }

            levels.push_back(sum);
        }

        int idx = max_element(levels.begin(), levels.end()) - levels.begin();

        return idx + 1;
    }
};