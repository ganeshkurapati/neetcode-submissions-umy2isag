class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right =0;
        int maxsize = 0;
        vector<int> visited(128, 0);
        while(right<s.length()){
            int offset = s[right];
            if(visited[offset]==0){
                visited[offset]++;
                maxsize = std::max(maxsize, right-left +1);
                right++;
            }
            else{
                visited[s[left]]--;
                left++;
            }
        }
        return maxsize;
    }
};
