class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_prod = nums[0], min_prod = nums[0], rc = nums[0];
        for(int i=1;i<n;i++){
            int prev_max_prod = max_prod;
            max_prod = max({nums[i], nums[i]*max_prod, nums[i]*min_prod});
            min_prod = min({nums[i], nums[i]*prev_max_prod, nums[i]*min_prod});
            rc = max(rc, max_prod);
        }
        return rc;
    }
};
