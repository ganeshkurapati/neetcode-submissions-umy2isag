class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        for(const auto&time : times){
            edges[time[0]].emplace_back(time[1],time[2]);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0,k});
        set<int> visited;
        int rc = 0;
        while(!minHeap.empty()){
            auto [currTime, node] = minHeap.top();
            minHeap.pop();
            if(visited.count(node)) continue;
            visited.insert(node);
            rc = currTime;
            for (auto &[neighbor, edgeTime] : edges[node]) {
                if (!visited.count(neighbor)) {
                    minHeap.push({currTime + edgeTime, neighbor});
                }
            }
        }
        return visited.size() == n ? rc : -1;
    }
};
