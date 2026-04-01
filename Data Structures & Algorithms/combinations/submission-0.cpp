class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        backtrack(0, n, k, comb);
        return res;
    }
private:
    void backtrack(int start, int n, int k, vector<int>& comb) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i < n; i++) {
            comb.push_back(i+1);
            backtrack(i + 1, n, k, comb);
            comb.pop_back();
        }
    }
};