class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int rc=0, count=0;
        for(int num: nums) {
            if(count==0) rc =num;
            count += (num==rc) ? 1:-1;
        }
        return rc;
    }
};