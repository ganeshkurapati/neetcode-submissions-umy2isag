class Solution {
public:
    int reverse(int x) {
        int rc = 0;
        while(x!=0){
            int digit = x%10;
            x /=10;
            // Check overflow before updating rc
            if (rc > INT_MAX / 10 || (rc == INT_MAX / 10 && digit > 7)) return 0;
            if (rc < INT_MIN / 10 || (rc == INT_MIN / 10 && digit < -8)) return 0;
            rc = rc * 10 + digit;
        }
        return rc;
    }
};
