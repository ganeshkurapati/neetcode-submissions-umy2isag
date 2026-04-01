class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        int res = r;
        while(l<=r) {
            int cap = (l+r)/2;
            if(canShip(weights, days, cap)) {
                res = min(res, cap);
                r = cap-1;
            }
            else l = cap + 1;
        }
        return res;
    }
private:
    bool canShip(const vector<int>& weights, int days, int cap) {
        int daysNeeded = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > cap) {
                daysNeeded++;       // start a new day
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return daysNeeded <= days;
    }
};