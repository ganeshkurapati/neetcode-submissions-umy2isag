class TrieNode{
public:
    TrieNode* child[26] = {nullptr};
    bool end_of_word = false;
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c: word){
            int i = c - 'a';
            if(curr->child[i]==nullptr) curr->child[i] = new TrieNode();
            curr = curr->child[i];
        }
        curr->end_of_word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(const string& word, int index, TrieNode* root){
        TrieNode* curr = root;
        for(int i=index;i<word.size();i++){
            char c = word[i];
            if(c=='.'){
                for(TrieNode* child : curr->child){
                    if(child!=nullptr) return dfs(word, i+1, child);
                }
                return false;
            }
            else{
                int i = c - 'a';
                if(curr->child[i]==nullptr) return false;
                curr = curr->child[i];
            }
        }
        return curr->end_of_word;
    }
};
