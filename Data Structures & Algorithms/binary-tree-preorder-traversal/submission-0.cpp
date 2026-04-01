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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rc;
        preorder(root, rc);
        return rc;
    }
private:
    void preorder(TreeNode* node, vector<int> &rc) {
        if(!node) return;
        rc.push_back(node->val);
        preorder(node->left, rc);
        preorder(node->right, rc);
    }
};