class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for(int i=0; i<n; i++) available.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;

        vector<int> count(n);

        for(const auto& meeting: meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            while(!used.empty() && used.top().first<=start) {
                int room = used.top().second;
                used.pop();
                available.push(room);
            }

            if(available.empty()) {
                auto curr = used.top();
                used.pop();
                end = curr.first + (end-start);
                available.push(curr.second);
            }

            int room = available.top();
            available.pop();
            used.push({end, room});
            count[room]++;
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};