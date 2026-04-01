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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
    */
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        unordered_map<TreeNode*, int> height;
        stack<pair<TreeNode*, bool>> st; 
        st.push({root, false});
        int diameter = 0;

        while (!st.empty()) {
            auto [node, visited] = st.top();
            st.pop();

            if (!node) continue;

            if (visited) {
                int leftH = node->left ? height[node->left] : 0;
                int rightH = node->right ? height[node->right] : 0;

                // Update global diameter
                diameter = max(diameter, leftH + rightH);

                // Store height for this node
                height[node] = 1 + max(leftH, rightH);
            } else {
                // Postorder: push current node again as visited
                st.push({node, true});
                // Push children
                st.push({node->right, false});
                st.push({node->left, false});
            }
        }

        return diameter;
    }
private:
    int dfs(TreeNode* root, int& diameter){
        if(!root) return 0;
        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
};
