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

    // My Approach , preorder traversal nodes are stored in vector, then loop throgh vector to connect them ..

    vector<TreeNode*> v;
    // void preorder(TreeNode* root) {
    //     if(root == NULL) return;

    //     v.push_back(root);
    //     preorder(root->left);
    //     preorder(root->right);
    // }

    // void flatten(TreeNode* root) {
    //     if(root == NULL) return;

    //     preorder(root);

    //     for(int i = 1; i < v.size(); i++) {
    //         v[i - 1]->left = NULL;
    //         v[i - 1]->right = v[i];
    //     }

    //     if(!v.empty()) {
    //         v.back()->left = NULL;
    //         v.back()->right = NULL;
    //     }
    // }


    // Most Optimal Approach ... O(1) space
    /*
        Preorder ko reverse me traverse kro , pre - VLR
        but in this case , hum ulta krenga , RLV
        NextPointer -> last visited node ko point krega ...
    */

    TreeNode *nextPointer = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextPointer;
        nextPointer = root;
    }
};