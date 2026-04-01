class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1) return false;
        vector<vector<int>> adj(n);
        for(const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> visit;
        queue<pair<int,int>>q;
        q.push({0,-1});
        visit.insert(0);
        while(!q.empty()){
            auto [node, parent] = q.front();
            q.pop();
            for(int n : adj[node]){
                if(n==parent) continue;
                if(visit.count(n)) return false;
                visit.insert(n);
                q.push({n, node});
            }
        }
        return visit.size()==n;
    }
};
