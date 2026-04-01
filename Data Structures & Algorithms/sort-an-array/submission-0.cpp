class Solution {
    private:
    void countSort(vector<int>& nums) {
        unordered_map<int, int> count;
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        for(auto& val : nums) count[val]++;
        int index = 0;
        for(int val = minVal; val<=maxVal; val++) {
            while(count[val]>0) {
                nums[index] = val;
                index++;
                count[val]--;
            }
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        countSort(nums);
        return nums;
    }
};