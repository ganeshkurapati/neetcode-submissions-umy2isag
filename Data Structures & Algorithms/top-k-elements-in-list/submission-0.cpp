class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size()+1);
        for(int num: nums){
            count[num]++;
        }
        for(const auto& c: count){
            freq[c.second].push_back(c.first);
        }
        vector<int> rc;
        for(int i = freq.size()-1;i>0;i--){
            for(int f: freq[i]){
                rc.push_back(f);
                if(rc.size()==k) return rc;
            }
        }
        return rc;
    }
};
