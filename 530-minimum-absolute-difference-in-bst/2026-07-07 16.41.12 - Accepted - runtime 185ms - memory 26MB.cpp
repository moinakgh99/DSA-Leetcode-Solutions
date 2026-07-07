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
    vector<int> v;

    void inorder(TreeNode *root) {
        if(root == NULL) return;

        getMinimumDifference(root->left);
        v.push_back(root->val);
        getMinimumDifference(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        
        inorder(root);

        int mini = INT_MAX;
        for(int i = 1; i < v.size(); i++) {
            mini = min(mini, abs(v[i] - v[i-1]));
        }

        return mini;
    }
};