class Solution {
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific (m, vector<bool>(n, false));
        vector<vector<bool>> atlantic (m, vector<bool>(n, false));
        for(int c=0; c<n; c++){
            dfs(heights, 0, c, pacific);
            dfs(heights, m-1, c, atlantic);
        }
        for(int r=0; r<m; r++){
            dfs(heights, r, 0, pacific);
            dfs(heights, r, n-1, atlantic);
        }
        vector<vector<int>> rc;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(pacific[r][c]&&atlantic[r][c]){
                    rc.push_back({r,c});
                }
            }
        }
        return rc;
    }
private:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited){
        visited[r][c] = true;
        for(auto& [dr, dc]: directions){
            int nr = r + dr, nc = c + dc;
            if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] &&
                heights[nr][nc] >= heights[r][c]){
                dfs(heights, nr, nc, visited);
            }
        }
    }
};
