/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL) return {};
        
        vector<int> res;
        for(Node *child : root->children) {
            vector<int> temp = postorder(child);

            // res.insert(position, start, end)
            res.insert(res.end(), temp.begin(), temp.end());
        }
        res.push_back(root->val);
        
        return res;
    }
};