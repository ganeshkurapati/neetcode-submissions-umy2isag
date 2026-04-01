class Solution {
public:
    bool isValid(string s) {
        stack<char> lookup;
        unordered_map<char,char> pair = {{')','('},{']','['},{'}','{'}};
        for(char c: s){
            if(pair.count(c)==0) {
                lookup.push(c);
            }
            else if (!lookup.empty() && lookup.top()==pair[c]){
                lookup.pop();
            }
            else
                return false;
        }
        return lookup.empty();
    }
};
