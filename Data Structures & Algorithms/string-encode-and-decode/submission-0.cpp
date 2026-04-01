class Solution {
public:

    string encode(vector<string>& strs) {
        string rc;
        for(const string& s: strs){
            rc += to_string(s.size()) + "#" + s;
        }
        return rc;
    }

    vector<string> decode(string s) {
        vector<string> rc;
        int curr = 0;
        while(curr<s.size()){
            int next = curr;
            while(s[next]!='#'){
                next++;
            }
            int len = stoi(s.substr(curr, next-curr));
            curr = next+1;
            next = curr+len;
            rc.push_back(s.substr(curr, len));
            curr = next;
        }
        return rc;
    }
};
