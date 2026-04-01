class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> rc(2*n);
        for(int i=0; i<n ; i++){
            rc[i]=rc[i+n]=nums[i];
        }
        return rc;
    }
};