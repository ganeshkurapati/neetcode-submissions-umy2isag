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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rc;
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
                rc.push_back(tmp.back());
        }
        return rc;
    }
    vector<int> rightSideViewDFS(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int depth, vector<int>& res) {
        if (!node) return;

        if (res.size() == depth) {
            res.push_back(node->val);
        }

        dfs(node->right, depth + 1, res);
        dfs(node->left, depth + 1, res);
    }
};
