#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);  // Visit node
            
            if (node->right) s.push(node->right);  // Push right child
            if (node->left) s.push(node->left);    // Push left child
        }
        return result;
    }
};