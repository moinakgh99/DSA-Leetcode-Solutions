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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(root == NULL) return res;

        queue<TreeNode*> q;
        TreeNode *p = root;

        q.push(p);

        while(!q.empty()) {
            int size = q.size();
            vector<int> levels;

            for(int i = 0; i < size; i++) {

                p = q.front();
                q.pop();

                levels.push_back(p->val);

                if(p->left) {
                    q.push(p->left);
                }
                if(p->right) {
                    q.push(p->right);
                }
            }
            res.push_back(levels);
        }

        return res;
    }
};