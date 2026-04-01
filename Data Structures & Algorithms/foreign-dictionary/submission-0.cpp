class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        // Step 1: Initialize indegree for all unique chars
        for(auto& word : words) {
            for(auto& ch : word) {
                indegree[ch] = 0;
            }
        }
        // Step 2: Build graph
        for(int i =0; i<words.size()-1; ++i) {
            string w1 = words[i];
            string w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            if(w1.size()>w2.size() && w1.substr(0, minLen)==w2) return "";
            for(int j=0;j<minLen;++j) {
                if(w1[j]!=w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    break; // only first differing character matters
                }
            }
        }
        // Step 3: Topological sort (Kahn’s)
        queue<char> q;
        for(auto& [ch, deg] : indegree) if(deg==0) q.push(ch);
        string order;
        while(!q.empty()) {
            char cur = q.front(); q.pop();
            order += cur;
            for(auto& nei : adj[cur]) {
                indegree[nei]--;
                if(indegree[nei]==0) q.push(nei);
            }
        }
        if (order.size() != indegree.size()) return ""; // cycle detected
        return order;
    }
};
