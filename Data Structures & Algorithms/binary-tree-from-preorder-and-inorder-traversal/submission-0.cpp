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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        int inorderIndex = 0;

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = st.top();

            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorder[i]);
                st.push(node->left);
            } else {
                while (!st.empty() && st.top()->val == inorder[inorderIndex]) {
                    node = st.top();
                    st.pop();
                    inorderIndex++;
                }
                node->right = new TreeNode(preorder[i]);
                st.push(node->right);
            }
        }
        return root;
    }
};
