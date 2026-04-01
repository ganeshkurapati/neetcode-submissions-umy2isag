class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int rc = right;
        while(left<=right){
            int mid = left + (right-left)/2;
            long long total_hours = 0;
            for(int p: piles){
                total_hours += (p + mid - 1) / mid;
            }
            if(total_hours<=h){
                rc = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return rc;
    }
};
