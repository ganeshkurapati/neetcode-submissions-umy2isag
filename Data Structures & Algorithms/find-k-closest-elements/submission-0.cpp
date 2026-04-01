class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         int lo = 0;
        int hi = arr.size() - k; // last valid window start

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // Compare left vs right boundary of the k-size window
            // If left is closer (or equal — prefer smaller), move window left
            if (x - arr[mid] <= arr[mid + k] - x) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        // Collect k elements starting at lo
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};