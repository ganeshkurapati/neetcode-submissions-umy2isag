class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;
        for(char c : path+"/") {
            if(c=='/') {
                if(curr=="..") {
                    if(!stack.empty()) stack.pop_back();
                } else if(!curr.empty() & curr!=".") stack.push_back(curr);
                curr.clear();
            }
            else curr += c;
        }
        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            if (i > 0) result += "/";
            result += stack[i];
        }

        return result;
    }
};