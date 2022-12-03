// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isBadVersion(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        // The loop terminate when low is larger than high
        // and low will point at the first bad version here
        return low;
    }
};
