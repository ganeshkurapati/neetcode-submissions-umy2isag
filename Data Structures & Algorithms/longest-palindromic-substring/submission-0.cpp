class Solution {
    void help(string& s, int left, int right, int& start, int& max_len){
        while(left>=0 && right< s.size() && s[left]==s[right]){
            int len = right-left+1;
            if(len>max_len){
                max_len = len;
                start = left;
            }
            left--;
            right++;
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        int start  = 0, max_len = 1;
        for(int i =0;i<n;i++){
            help(s,i,i,start,max_len);
            help(s,i,i+1,start,max_len);
        }
        return s.substr(start, max_len);
    }
};
