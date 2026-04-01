class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rc;
        vector<int> curr;
        backtrack(nums, 0, curr, rc);
        return rc;
    }
private:
    void backtrack(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& rc){
        rc.push_back(curr);
        for(int i = index; i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(nums, i+1, curr, rc);
            curr.pop_back();
        }
    }

};
