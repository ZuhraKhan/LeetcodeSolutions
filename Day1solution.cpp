/*You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies
 of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each .
child gets the same number of candies. Each child can be allocated candies from only one pile of candies
 and some piles of candies may go unused.

Return the maximum number of candies each child can get.

 

Example 1:

Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 
2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can
 allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.*/
 
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        int max_candies = 0;

        for (int c : candies) {
            sum += c;
            max_candies = max(max_candies, c);
        }

        // If total candies < k, it's impossible to distribute
        if (sum < k) return 0;

        int l = 1, r = max_candies;  // Start search from 1 to avoid division by zero
        while (l <= r) {
            int middle = l + (r - l) / 2;  // Avoid overflow
            if (canAllocate(candies, k, middle)) {
                l = middle + 1;
            } else {
                r = middle - 1;
            }
        }
        return r;  // r will be the largest valid pile size
    }

private:
    bool canAllocate(vector<int>& candies, long long k, int num) {
        long long count = 0;
        for (int c : candies) {
            count += c / num;
        }
        return count >= k;
    }
};
