class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        for(int i =nums.size()-2;i>=0;i--){
            if(i+nums[i]>=goal){
                goal = i;
            }
        }
        return goal==0;
    }
    bool canJump2(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > farthest) return false; // can't even reach index i
            farthest = max(farthest, i + nums[i]);
        }

        return true; // reached or passed the last index
    }
};
