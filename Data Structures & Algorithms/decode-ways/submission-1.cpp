class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s.empty() || s[0]=='0') return 0;
        int prev2 = 0;
        int prev1 = 1;
        for(int i = 0; i< n;i++){
            int curr = 0;
            if(s[i]!='0') curr += prev1;
            if(i>=0 && s[i-1]=='1' || s[i-1]=='2' && s[i]<'7') curr += prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
