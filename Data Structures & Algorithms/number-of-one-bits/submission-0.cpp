class Solution {
public:
    int hammingWeight(uint32_t n) {
        int rc = 0;
        while(n){
            n &= n-1;
            rc++;
        }
        return rc;
    }
};
