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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        TreeNode *p = root;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        long long maxi = LLONG_MIN;
        while(!q.empty()) {
            int size = q.size();
            long long first = q.front().second;

            vector<long long> levels;
            for(int i = 0; i < size; i++) {
                p = q.front().first;
                long long idx = q.front().second - first;
                q.pop();

                levels.push_back(idx);

                if(p->left) q.push({p->left, 2 * idx + 1});
                if(p->right) q.push({p->right, 2 * idx + 2});
            }

            int l = 0, r = levels.size() - 1;
            maxi = max(maxi, levels[r] - levels[l] + 1); 
        }

        return maxi;
    }
};