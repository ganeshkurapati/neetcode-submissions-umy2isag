class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
         // Sort intervals by start
        sort(intervals.begin(), intervals.end());

        // Store original query indices
        vector<pair<int,int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end()); // sort queries by value

        vector<int> result(queries.size(), -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int i = 0; // index for intervals
        for (auto [query, idx] : q) {
            // Add intervals starting <= query
            while (i < intervals.size() && intervals[i][0] <= query) {
                int l = intervals[i][0], r = intervals[i][1];
                pq.push({r - l + 1, r}); // push length and end
                i++;
            }

            // Remove intervals that end < query
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            // If valid interval exists
            if (!pq.empty()) {
                result[idx] = pq.top().first;
            }
        }
        return result;       
    }
};
