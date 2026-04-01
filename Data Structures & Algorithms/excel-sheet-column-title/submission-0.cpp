class Solution {
public:
    string convertToTitle(int columnNumber) {
        string rc;
        while (columnNumber>0) {
            columnNumber--;
            int offset = columnNumber%26;
            rc += 'A' + offset;
            columnNumber /= 26;
        }
        reverse(rc.begin(), rc.end());
        return rc;
    }
};