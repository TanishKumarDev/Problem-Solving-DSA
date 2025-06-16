#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force

Intuition:
- Try every possible subarray (from index i to j).
- For each subarray:
    1. Calculate the sum of elements.
    2. Calculate the score = sum * length.
    3. If score < k, count it as valid.

Time Complexity: O(n^2) — for each i, we go from j = i to n.
Space Complexity: O(1) — constant extra space.
*/

class BruteForceSolution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];  // Accumulate sum from i to j
                long long length = j - i + 1;
                long long score = sum * length;
                if (score < k) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};


/*
Approach 2: Sliding Window (Optimal)

Observations:
- Subarrays must have score < k, where score = sum * length.
- We maintain a window [left..right] such that score < k.
- All subarrays ending at `right` and starting from `left` to `right` are valid.

Intuition:
- Expand the window to include nums[right].
- If the score becomes >= k, shrink from the left until it becomes valid.
- For each valid window, count the subarrays ending at `right`.

Time Complexity: O(n) — each element is added and removed at most once.
Space Complexity: O(1)
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;         // Final answer to store count of valid subarrays
        long long sum = 0;         // Current window sum
        int left = 0;              // Left index of the sliding window

        // Iterate through each element as the right end of the window
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];  // Include current element in window

            // While current window's score is not valid, shrink from the left
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];  // Remove element at `left`
                ++left;             // Move left pointer forward
            }

            // Number of valid subarrays ending at 'right' = (right - left + 1)
            ans += (right - left + 1);
        }

        return ans;
    }
};


//  Testing both approaches
int main() {

    return 0;
}
