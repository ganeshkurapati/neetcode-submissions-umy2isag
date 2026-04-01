class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
                int rows = grid.size(), cols = grid[0].size();
        queue<pair<pair<int,int>, int>> q;  // {{row, col}, time}
        int fresh = 0;

        // Step 1: Add all rotten fruits to the queue, count fresh
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({{r, c}, 0});
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        // Directions: up, down, left, right
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int minutes = 0;

        // Step 2: BFS
        while (!q.empty()) {
            auto [pos, time] = q.front();
            q.pop();
            int r = pos.first, c = pos.second;
            minutes = max(minutes, time);

            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // make rotten
                    fresh--;
                    q.push({{nr, nc}, time + 1});
                }
            }
        }

        // Step 3: If fresh fruits remain → impossible
        return fresh == 0 ? minutes : -1;
    }
};
