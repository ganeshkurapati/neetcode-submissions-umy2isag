class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int lo = 0;
        int hi = people.size() - 1;
        int boats = 0;

        while (lo <= hi) {
            if (people[lo] + people[hi] <= limit) {
                lo++;
            }
            hi--;
            boats++;
        }

        return boats;
    }
};