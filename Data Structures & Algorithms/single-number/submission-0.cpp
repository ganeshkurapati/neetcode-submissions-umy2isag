class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rc = 0;
        for(int num: nums){
            rc ^= num;
        }
        return rc;
    }
};
