class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rc;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(nums, curr,  used, rc);
        return rc;
    }
private:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& rc){
        if(curr.size()==nums.size()){
            rc.push_back(curr);
            return;
        }
        for(int i = 0; i<nums.size();i++){
            if(used[i]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, curr, used, rc);
            curr.pop_back();
            used[i] = false;
        }
    }
};
