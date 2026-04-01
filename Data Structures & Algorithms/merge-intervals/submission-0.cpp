class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        int write_index = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=intervals[write_index][1]){
                intervals[write_index][1] = max(intervals[write_index][1], intervals[i][1]);
            }
            else{
                write_index++;
                intervals[write_index] = intervals[i];
            }
        }
        intervals.resize(write_index+1);
        return intervals;
    }
};
