class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j, m, n);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;        
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0; // mark visited
        int area = 1;

        area += dfs(grid, i + 1, j, m, n);
        area += dfs(grid, i - 1, j, m, n);
        area += dfs(grid, i, j + 1, m, n);
        area += dfs(grid, i, j - 1, m, n);

        return area;
    }
    int maxAreaOfIslandBFS(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        area++;

                        for (auto [dx, dy] : directions) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                                grid[nx][ny] = 0;
                                q.push({nx,ny});
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
