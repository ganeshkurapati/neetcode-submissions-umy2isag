class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for(const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for(auto& [src, destinations] : adj) {
            sort(destinations.rbegin(), destinations.rend());
        }
        vector<string> rc;
        stack<string> s;
        s.push("JFK");
        while(!s.empty()){
            string curr = s.top();
            if(adj[curr].empty()) {
                rc.push_back(curr);
                s.pop();
            } else {
                string next = adj[curr].back();
                adj[curr].pop_back();
                s.push(next);
            }
        }
        reverse(rc.begin(), rc.end());
        return rc;
    }
};
