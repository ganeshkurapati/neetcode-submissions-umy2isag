class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return (tasks[a][0] < tasks[b][0]) || (tasks[a][0]==tasks[b][0] && a<b); 
        });

        auto cmp = [&](int a , int b) {
            return (tasks[a][1] > tasks[b][1]) || (tasks[a][1]==tasks[b][1] && a>b);
        };

        priority_queue<int , vector<int>, decltype(cmp)> minHeap(cmp);

        vector<int> rc;
        long long curTime = 0;
        int i = 0;
        while(!minHeap.empty() || i<n) {
            while(i<n && tasks[indices[i]][0] <= curTime) {
                minHeap.push(indices[i]);
                i++;
            }
            if(minHeap.empty()) curTime = tasks[indices[i]][0];
            else{
                int next = minHeap.top();
                minHeap.pop();
                curTime += tasks[next][1];
                rc.push_back(next);
            }
        }
        return rc;
    }
};