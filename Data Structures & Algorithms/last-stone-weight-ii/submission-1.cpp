class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = stoneSum / 2;
        vector<int> dp(target + 1, 0);

        for (int stone : stones) {
            for (int t = target; t >= stone; t--) {
                dp[t] = max(dp[t], dp[t - stone] + stone);
            }
        }

        return stoneSum - 2 * dp[target];
    }
};