class Solution {
        void help(string& s, int left, int right, int& count){
        while(left>=0 && right< s.size() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i =0;i<n;i++){
            help(s,i,i,count);
            help(s,i,i+1,count);
        }
        return count;
    }
};
