class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr; vector<vector<int>> rc;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, curr, rc);
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
            if(i>index && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            curr.push_back(nums[i]);
            backtrack(nums, target-nums[i], i+1, curr, rc);
            curr.pop_back();
        }
    }
};
