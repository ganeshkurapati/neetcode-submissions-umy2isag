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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> rc;
        postorder(root, rc);
        return rc;
    }
private:
    void postorder(TreeNode* node, vector<int> &rc) {
        if(!node) return;
        postorder(node->left, rc);
        postorder(node->right, rc);
        rc.push_back(node->val);
    }
};