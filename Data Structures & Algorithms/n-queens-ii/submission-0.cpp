class Solution {
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
public:
    int totalNQueens(int n) {
        int rc = 0;
        backtrack(0, n, rc);
        return rc;
    }
private:
    void backtrack(int r, int n, int& rc){
        if(r==n){
            rc++;
            return;
        }
        for(int c = 0;c<n;c++){
            if(col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) continue;
            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            backtrack(r + 1, n, rc);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    }
};