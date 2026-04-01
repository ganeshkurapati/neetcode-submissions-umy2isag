class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& flight : flights){
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        queue<tuple<int, int, int>> q;
        q.push({0, src, 0}); //{cost, node, stops}
        while(!q.empty()){
            auto [cost, node, stops] = q.front(); q.pop();
            if(stops>k) continue;
            for(const auto& [neighbor, price] : adj[node]){
                int newCost = cost + price;
                if(newCost < prices[neighbor]){
                    prices[neighbor] = newCost;
                    q.push({newCost, neighbor, stops+1});
                }
            }
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
