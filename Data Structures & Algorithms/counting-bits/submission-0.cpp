class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> rc(n+1, 0);
        for(int i=0;i<=n;i++){
            rc[i] = rc[i>>1] + (i&1);
        }
        return rc;
    }
};
