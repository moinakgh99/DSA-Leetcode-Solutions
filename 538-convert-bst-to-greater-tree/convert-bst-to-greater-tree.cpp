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

    /*
        Approach : Inorder traversal of bst is always sorted, goes from LVR...
        for this ques, we will do traversal from RVL ....
        update sum as well ...
    */

    void CalcSum(TreeNode* root, int &sum) {
        if(root == NULL) return;

        CalcSum(root->right, sum);
        sum += root->val;
        root->val = sum;
        CalcSum(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return NULL;

        int sum = 0;

        CalcSum(root, sum);

        return root;
    }
};