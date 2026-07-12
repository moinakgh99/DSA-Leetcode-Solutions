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

    // My Approach ....
    /*
        if level is odd -> push right first , then left
        if level is even -> push left first, then right

        maintain a queue for that, for each size , push that into the queue, check the condition for level
    */
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        TreeNode *p = root;

        q.push(root);
        int c = 1;

        while(!q.empty()) {
            int size = q.size();
            vector<int> levels;

            for(int i = 0; i < size; i++) {
                p = q.front();
                int node = p->val;
                q.pop();

                levels.push_back(node);

                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);

            }

            if(c % 2 == 0) {
                reverse(levels.begin(), levels.end());
            }
            
            c++;
            res.push_back(levels);
        }

        return res;
    }
};