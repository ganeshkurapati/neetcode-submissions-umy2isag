class Solution {
private:
    vector<vector<int>> dp;
public:
    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);
        int n = piles.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int aliceScore = dfs(0, n-1, piles);
        return aliceScore > total - aliceScore; 
    }
private:
    int dfs(int l, int r, const vector<int>& piles) {
        if(l>r) return 0;
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        bool even = (r-l)%2 == 0;
        int left = even? piles[l] : 0;
        int right = even? piles[r] : 0;
        dp[l][r] =max(dfs(l+1, r, piles)+ left, dfs(l, r-1, piles) + right);
        return dp[l][r];
    }
};