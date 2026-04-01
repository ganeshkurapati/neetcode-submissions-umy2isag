class Solution {
    vector<vector<bool>> visit;
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->visit.assign(board.size(), vector<bool>(board[0].size(), false));
        for(size_t i = 0; i<board.size(); i++){
            for(size_t j=0; j<board[0].size();j++){
                if(board[i][j]!=word[0]) continue;
                if(this->dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int row, int col){
        if(index>=word.size()) return true;
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size()) return false;
        if((board[row][col]!=word[index]) || visit[row][col]) return false;
        this->visit[row][col] = true;
        bool rc =  dfs(board, word, index+1, row+1, col) || dfs(board, word, index+1, row-1, col)
        || dfs(board, word, index+1, row, col+1) || dfs(board, word, index+1, row, col-1);
        this->visit[row][col] = false;
        return rc;
    }    
};
