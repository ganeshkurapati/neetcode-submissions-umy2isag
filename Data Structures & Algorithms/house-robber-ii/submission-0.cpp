class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> option1(nums.begin()+1, nums.end());
        vector<int> option2(nums.begin(), nums.end()-1);
        return max(robLinear(option1), robLinear(option2));
    }
private:
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        int prev1 = 0, prev2 = 0;
        for(int i = 0; i<n; i++){
            int curr = max(nums[i]+prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;        
    }
};
