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
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c: word){
            int i = c - 'a';
            if(curr->child[i]==nullptr) return false;
            curr = curr->child[i];
        }
        return curr->end_of_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix){
            int i = c - 'a';
            if(curr->child[i]==nullptr) return false;
            curr = curr->child[i];
        }
        return true;
    }
};
