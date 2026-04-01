class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // stores indices
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            // Remove smaller elements (not useful)
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Remove out-of-window element
            if (dq.front() <= i - k)
                dq.pop_front();

            // Record max once window reaches size k
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
