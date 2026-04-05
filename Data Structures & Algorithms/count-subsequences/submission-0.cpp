class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<uint> dp(n + 1, 0);
        dp[0] = 1; // empty t base case

        for (int i = 1; i <= m; i++) {
            // Traverse right to left to avoid using updated values
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};
