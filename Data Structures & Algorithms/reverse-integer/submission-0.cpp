class Solution {
public:
    int reverse(int x) {
        long rc = 0;
        while(x!=0){
            int digit = x%10;
            x /=10;
            rc = rc * 10 + digit;
        }
        if(rc>INT_MAX || rc< INT_MIN) return 0;
        return rc;
    }
};
