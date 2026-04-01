class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        minHeap.push({0,0,0});
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int diff = curr[0], r = curr[1], c = curr[2];
            if(r== rows-1 && c==cols-1) return diff;
            if(dist[r][c] < diff) continue;

            for(auto& dir :  directions) {
                int nr = r+dir[0], nc = c+dir[1];
                if(nr<0 || nc <0 || nr>=rows || nc>=cols) continue;

                int ndiff = max(diff, abs(heights[r][c]- heights[nr][nc]));
                if(ndiff< dist[nr][nc]) {
                    dist[nr][nc] = ndiff;
                    minHeap.push({ndiff, nr, nc});
                }
            }
        }
        return 0;
    }
};