class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long remaining = (long long)(n - 1);  // bits to spread

        // Walk bit positions; for each free slot in x, consume one bit of remaining
        for (long long bit = 1; remaining > 0; bit <<= 1) {
            if (!(x & bit)) {               // free bit position
                if (remaining & 1)          // LSB of remaining goes here
                    result |= bit;
                remaining >>= 1;            // consume one bit
            }
            // set bits of x: always preserved, skip
        }
        return result;
    }
};