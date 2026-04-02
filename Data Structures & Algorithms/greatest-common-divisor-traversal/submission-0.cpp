class UnionFind {
    vector<int> parent;
    vector<int> rank;
    int n;

public:
    UnionFind(int n) : n(n){
        parent.resize(n+1);
        rank.resize(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x1, int x2) {
        int p1 = find(x1);
        int p2 = find(x2);
        if (p1 == p2) {
            return false;
        }
        n--;
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
    bool connected() { return n==1; }
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        // Also: if any element is 1 and n > 1
        // it can never connect → false immediately
        for (int x : nums)
            if (x == 1) return n == 1;  
        UnionFind uf(n);
        unordered_map<int, int> factor_index;
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            for(int f = 2; f*f <= num; f++) {
                if(num%f == 0) {
                    if(factor_index.count(f)) 
                        uf.unionSets(i, factor_index[f]);
                    else factor_index[f] = i;
                    while(num%f == 0) num /= f;
                } 
            }
            if(num > 1) {
                if(factor_index.count(num)) 
                    uf.unionSets(i, factor_index[num]);
                else factor_index[num] = i;
            }
        }
        return uf.connected();
    }
};