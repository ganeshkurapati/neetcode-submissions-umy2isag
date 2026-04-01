class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), node = 0;
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        int edges = 0, rc =0;
        while(edges < n-1){
            visited[node] = true;
            int next = -1;
            for(int i=0; i<n; i++){
                if(visited[i]) continue;
                int curDist = abs(points[i][0]-points[node][0]) +
                                abs(points[i][1]-points[node][1]);
                dist[i] = min(curDist, dist[i]);
                if(next==-1 || dist[i]<dist[next]){
                    next = i;
                }
            }
            rc += dist[next];
            node = next;
            edges++;
        }
        return rc;
    }
};
