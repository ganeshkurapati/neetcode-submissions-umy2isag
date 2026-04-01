class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x;
        int rc=0;
        while(l<=r){
            int m = l+(r-l)/2;
            if((long long)m*m>x) r=m-1;
            else if((long long)m*m<x) {
                l=m+1;
                rc=m;
            }
            else return m;
        }
        return rc;
    }
};