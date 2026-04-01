class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> rc;
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right){
                int val = nums[i] + nums[left] + nums[right];
                if(val==0){
                    rc.push_back({nums[i] , nums[left] , nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    left++;
                    right--;
                }
                else if(val<0){
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return rc;
    }
};
