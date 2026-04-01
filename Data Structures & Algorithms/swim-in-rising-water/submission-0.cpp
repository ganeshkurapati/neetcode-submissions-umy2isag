class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({grid[0][0],0,0}); // elevation, row, col
        visited[0][0] = true;
        int rc = 0;
        while(!minHeap.empty()) {
            auto curr = minHeap.top();
            int elev = curr[0], r = curr[1], c = curr[2];
            minHeap.pop();
            rc = max(rc, elev);
            if(r==n-1 && c==n-1) return rc;
            for(auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if(nr>=0 && nc>=0 && nr<n && nc<n && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    minHeap.push({grid[nr][nc],nr,nc});
                }
            }
        }
        return rc;
    }
};
