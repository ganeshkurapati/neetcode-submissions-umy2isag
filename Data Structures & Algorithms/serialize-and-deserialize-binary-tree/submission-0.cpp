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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        string rc;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if (!curr) rc += "N,";
            else{
                rc += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return rc;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="N") return nullptr;
        vector<string> nodes = split(data);
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* node = q.front(); q.pop();

            if (nodes[i] != "N") {
                node->left = new TreeNode(stoi(nodes[i]));
                q.push(node->left);
            }
            i++;

            if (i < nodes.size() && nodes[i] != "N") {
                node->right = new TreeNode(stoi(nodes[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
private:
    vector<string> split(const string &data) {
        vector<string> res;
        string s = "";
        for (char c : data) {
            if (c == ',') {
                res.push_back(s);
                s = "";
            } else {
                s += c;
            }
        }
        res.push_back(s); // push last element
        return res;
    }
};
