class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        while(!q.empty()){
            int node = q.front();
            q.pop();
            finish++;
            for(int n: adj[node]){
                incoming[n]--;
                if(incoming[n]==0) q.push(n);
            }
        }

        return finish==numCourses;

    }
};
