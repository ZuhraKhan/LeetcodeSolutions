#include <vector>
#include <algorithm>
#include <cmath>  // For sqrt

using namespace std;

class Solution {
public:
    bool canRepairInTime(const vector<int>& ranks, int cars, long long mid) {
        long long totalCars = 0;
        for (int rank : ranks) {
            totalCars += (long long)sqrt((double)mid / rank);  // Proper typecast
            if (totalCars >= cars) return true; // Early exit optimization
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars;  // Use valid upper bound
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
