class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int rc = 0;
        for(int n: nums){
            if(nums_set.count(n-1)==0){
                int len = 1;
                while(nums_set.count(n+len)!=0){
                    len++;
                }
                rc = max(rc, len);
            }
        }
        return rc;
    }
};
