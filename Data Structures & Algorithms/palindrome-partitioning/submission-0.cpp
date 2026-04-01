class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> rc;
        backtrack(s, 0, curr, rc);
        return rc;
    }
private:
    void backtrack(const string& s, int index, vector<string>& curr, vector<vector<string>>& rc){
        if(index==s.size()){
            rc.push_back(curr);
            return;
        }
        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i-index+1));
                backtrack(s, i+1, curr, rc);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(const string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
