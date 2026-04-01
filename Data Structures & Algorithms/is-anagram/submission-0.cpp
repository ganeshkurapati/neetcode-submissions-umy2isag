class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> lookup(26, 0);
        for(int i =0; i<s.size(); i++){
            lookup[s[i]-'a']++;
            lookup[t[i]-'a']--;
        }
        for(int c: lookup){
            if(c!=0) return false;
        }
        return true;
    }
};
