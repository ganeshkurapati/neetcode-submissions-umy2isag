class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> incoming(numCourses, 0);

        for(auto& p : prerequisites){
            adj[p[0]].push_back(p[1]);
            incoming[p[1]]++;
        }

        queue<int> q;
        for(int c=0; c<numCourses; c++){
            if(incoming[c]==0) q.push(c);
        }

        int finish =0;
        vector<int> rc(numCourses);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            rc[numCourses - finish -1] = node;
            finish++;
            for(int n: adj[node]){
                incoming[n]--;
                if(incoming[n]==0) q.push(n);
            }
        }

        if(finish!=numCourses) return {};
        return rc;
    }
};
