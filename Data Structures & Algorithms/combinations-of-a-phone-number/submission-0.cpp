class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> rc;
        string curr;
        backtrack(digits, 0, curr, rc);
        return rc;
    }
private:
    const vector<string> keypad = {
        "",    "",    "abc",  "def",
        "ghi", "jkl", "mno",  "pqrs",
        "tuv", "wxyz"
    };
    void backtrack(const string& digits, int index, string& curr, vector<string>& rc){
        if(index==digits.size()){
            rc.push_back(curr);
            return;
        }
        int digit = digits[index] - '0';
        for(char ch: keypad[digit]){
            curr.push_back(ch);
            backtrack(digits, index+1, curr, rc);
            curr.pop_back();
        }
    }
};
