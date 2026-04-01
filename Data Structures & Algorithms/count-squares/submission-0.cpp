class CountSquares {
    unordered_map<int, unordered_map<int, int>> lookup;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        lookup[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int rc = 0;
        int x1 = point[0], y1 = point[1];
        for(auto& [y2, count]: lookup[x1]){
            int side = y2 - y1;
            if (side==0) continue;
            int x3 = x1+side, x4 = x1-side;
            rc += count * lookup[x3][y1] * lookup[x3][y2];
            rc += count * lookup[x4][y1] * lookup[x4][y2];
        }
        return rc;
    }
};
