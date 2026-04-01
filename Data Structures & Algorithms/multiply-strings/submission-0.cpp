class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> rc(m+n, 0);
        for(int i=m-1;i>=0;i--){
            int digit1 = num1[i] - '0';
            for(int j =n-1;j>=0;j--){
                int digit2 = num2[j] - '0';
                int prod = rc[i+j+1] + digit1 * digit2;
                rc[i+j+1] = prod%10;
                rc[i+j] += prod/10;
            }
        }
        string result;
        for(int d: rc){
            if(!(result.empty() && d==0))
                result.push_back(d+'0');
        }
        return result.empty()? "0": result;
    }
};
