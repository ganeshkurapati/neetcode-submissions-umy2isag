class TrieNode{
public:
    TrieNode* child[26] = {nullptr};
    bool end_of_word = false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c: word){
            int i = c - 'a';
            if(curr->child[i]==nullptr) curr->child[i] = new TrieNode();
            curr = curr->child[i];
        }
        curr->end_of_word = true;
    }
    
    bool search(string& word, int i, int j) {
        TrieNode* curr = root;
        for(int idx = i; idx <= j; ++idx){
            int i = word[idx] - 'a';
            if(curr->child[i]==nullptr) return false;
            curr = curr->child[i];
        }
        return curr->end_of_word;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        PrefixTree prefixTree;
        for (string word : wordDict) {
            prefixTree.insert(word);
        }
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=0; i<n; i++){
            if(!dp[i]) continue;
            for(int j=i; j<n ; ++j){
                if(prefixTree.search(s, i, j)){
                    dp[j+1] = true;
                }
            }
        }
        return dp[n];
    }
};
