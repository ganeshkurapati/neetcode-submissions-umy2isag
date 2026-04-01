class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> rc(n, 0);
        stack<int> lookup;
        for(int i=0;i<n;i++){
            while(!lookup.empty() && temperatures[i]>temperatures[lookup.top()]){
                int index = lookup.top();
                lookup.pop();
                rc[index] = i - index;
            }
            lookup.push(i);
        }
        return rc;
    }
};
