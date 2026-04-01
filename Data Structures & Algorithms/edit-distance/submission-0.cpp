class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1);

        // Init first row
        for (int j = 0; j <= n; j++) dp[j] = j;

        for (int i = 1; i <= m; i++) {
            int prev = dp[0];       // stores dp[i-1][j-1] (diagonal)
            dp[0] = i;              // base case: delete i chars

            for (int j = 1; j <= n; j++) {
                int temp = dp[j];   // save before overwrite (will be diagonal for j+1)
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = prev;               // diagonal, free
                } else {
                    dp[j] = 1 + min({
                        prev,       // dp[i-1][j-1] replace
                        dp[j],      // dp[i-1][j]   delete
                        dp[j-1]     // dp[i][j-1]   insert
                    });
                }
                prev = temp;        // shift diagonal
            }
        }
        return dp[n];
    }
};
