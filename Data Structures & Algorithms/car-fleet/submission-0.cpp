class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars(n);
        for(int i =0; i<n; i++){
            cars[i] = {position[i], (double)(target-position[i])/speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double last_time = 0.0;
        for(auto &[pos, time]: cars){
            if(time>last_time){
                fleets++;
                last_time = time;
            }
        }
        return fleets;
    }
};
