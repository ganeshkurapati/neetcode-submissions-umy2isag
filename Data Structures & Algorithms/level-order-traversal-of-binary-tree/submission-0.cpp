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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rc;
        queue<TreeNode*> S;
        S.push(root);
        while(!S.empty()){
            vector<int> tmp;
            int S_len = S.size();
            for(int len=0;len<S_len;len++){
                TreeNode* curr = S.front();
                S.pop();
                if(curr==nullptr) continue;
                tmp.push_back(curr->val);
                if(curr->left!=nullptr){
                    S.push(curr->left);
                }
                if(curr->right!=nullptr){
                    S.push(curr->right);
                }
            }
            if(!tmp.empty())
                rc.push_back(tmp);
        }
        return rc;
    }
    vector<vector<int>> levelOrderDFS(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
private:
    void dfs(TreeNode* node, int depth, vector<vector<int>>& result) {
        if (!node) return;

        // Ensure this depth exists
        if (result.size() == depth) {
            result.push_back({});
        }

        result[depth].push_back(node->val);

        dfs(node->left, depth + 1, result);
        dfs(node->right, depth + 1, result);
    }
};
