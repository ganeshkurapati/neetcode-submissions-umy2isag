class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for(size_t i = 0; i<board.size(); i++){
            for(size_t j=0; j<board[0].size();j++){
                if(board[i][j]!=word[0]) continue;
                if(this->dfs(board, word, 0, i, j, visit)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int row, int col, vector<vector<bool>>& visit){
        if(index>=word.size()) return true;
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size()) return false;
        if((board[row][col]!=word[index]) || visit[row][col]) return false;
        visit[row][col] = true;
        bool rc =  dfs(board, word, index+1, row+1, col, visit) || dfs(board, word, index+1, row-1, col, visit)
        || dfs(board, word, index+1, row, col+1, visit) || dfs(board, word, index+1, row, col-1, visit);
        visit[row][col] = false;
        return rc;
    }    
};
