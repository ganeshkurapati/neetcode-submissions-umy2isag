class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr; vector<vector<int>> rc;
        backtrack(nums, target, 0, curr, rc);
        return rc;
    }
private:
    void backtrack(vector<int>& nums, int target, int index, vector<int>& curr, vector<vector<int>>& rc){
        if(target==0){
            rc.push_back(curr);
            return;
        }
        if(target<0) return;
        for(int i = index;i<nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(nums, target-nums[i], i, curr, rc);
            curr.pop_back();
        }
    }
};
