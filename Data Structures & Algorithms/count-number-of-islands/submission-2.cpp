class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int num = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    num++;
                    dfs(grid, i, j);
                }
            }
        }
        return num;        
    }
private:
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) return;
        if(grid[row][col]=='0') return;
        grid[row][col]='0';
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
    }    
    int numIslandsBFS(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int count = 0;
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '0';
                    queue<pair<int,int>> q;
                    q.push({i,j});

                    while(!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for (auto [dx, dy] : directions) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >=0 && ny >=0 && nx < m && ny < n && grid[nx][ny]=='1') {
                                grid[nx][ny]='0';
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
