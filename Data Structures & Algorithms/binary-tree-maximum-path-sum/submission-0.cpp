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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        help(root, max_sum);
        return max_sum;
    }
private:
     int help(TreeNode* root, int& max_sum){
         if(root!=nullptr){
            int l = help(root->left, max_sum);
            int r = help(root->right, max_sum);
            max_sum = max(max_sum, l+r+root->val);
            max_sum = max(max_sum, l+root->val);
            max_sum = max(max_sum, r+root->val);
            max_sum = max(max_sum, root->val);
            return max(max(l, r) + root->val, root->val);
        }
        return 0;
    }
};
