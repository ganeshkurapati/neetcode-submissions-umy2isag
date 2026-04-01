class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapAnagrams;
        for(const string& str: strs){
            vector<int> count(26,0);
            for(const char& c: str){
                count[c-'a']++;
            }
            string key;
            for(int i=0;i<26;i++){
                key += ','+ to_string(count[i]);
            }
            mapAnagrams[key].push_back(str);
        }
        vector<vector<string>> rc;
        for(const auto&pair: mapAnagrams){
            rc.push_back(pair.second);
        }
        return rc;
    }
};
