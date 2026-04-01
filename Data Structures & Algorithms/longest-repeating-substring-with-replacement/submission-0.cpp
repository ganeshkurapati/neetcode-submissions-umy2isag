class Solution {
public:
    int characterReplacement(string s, int k) {
        size_t n = s.size();
        int left = 0;
        int rc = 0;
        int maxWindow = 0;
        vector<int> count(26, 0);
        for(int right = 0; right<n;right++){
            count[s[right]-'A']++;
            maxWindow = std::max(maxWindow, count[s[right]-'A']);
            while((right-left+1)-maxWindow > k){
                count[s[left]-'A']--;
                left++;
            }
            rc = std::max(rc, right-left+1);
        }
        return rc;
    }
};
