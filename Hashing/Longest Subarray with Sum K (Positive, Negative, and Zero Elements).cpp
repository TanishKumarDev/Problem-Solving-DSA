#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force Approach: O(n^3) Time | O(1) Space
// Checks all possible subarrays using 3 nested loops
long long longestSubarrayBrute(vector<int>& arr, long long k) {
    int n = arr.size();
    long long maxLen = 0;

    // Outer loop selects the starting index i
    for (int i = 0; i < n; i++) {
        // Middle loop selects the ending index j
        for (int j = i; j < n; j++) {
            long long sum = 0;
            // Inner loop calculates the sum of subarray [i..j]
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            // Check if the current subarray sum equals k
            if (sum == k) {
                // Update max length
                maxLen = max(maxLen, (long long)(j - i + 1));
            }
        }
    }
    return maxLen;
}

// 🟡 Better Approach: O(n^2) Time | O(1) Space
// Removes the innermost loop by maintaining running sum in middle loop
long long longestSubarrayBetter(vector<int>& arr, long long k) {
    int n = arr.size();
    long long maxLen = 0;

    // Outer loop for starting index
    for (int i = 0; i < n; i++) {
        long long sum = 0;

        // Inner loop calculates sum of subarray [i..j]
        for (int j = i; j < n; j++) {
            sum += arr[j];

            // Check if current subarray sum equals k
            if (sum == k) {
                maxLen = max(maxLen, (long long)(j - i + 1));
            }
        }
    }
    return maxLen;
}

// 🟢 Optimal Approach: O(n log n) with map, O(n) average with unordered_map | O(n) Space
// Uses prefix sum and hashing (prefix sum technique)
long long longestSubarrayWithSumK(vector<int>& arr, long long k) {
    int n = arr.size();
    long long sum = 0, maxLen = 0;

    // Stores prefix sum and its earliest index
    map<long long, int> preSumMap;

    preSumMap[0] = -1; // Important: prefix sum 0 occurs before index 0 (empty subarray)

    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Update running sum

        // If running sum equals k, update maxLen
        if (sum == k) {
            maxLen = max(maxLen, (long long)(i + 1));
        }

        // If (sum - k) has been seen before, that means subarray from
        // preSumMap[sum - k] + 1 to i has sum k
        if (preSumMap.find(sum - k) != preSumMap.end()) {
            int len = i - preSumMap[sum - k];
            maxLen = max(maxLen, (long long)len);
        }

        // Store current sum only if it's not already in map
        // because we want the longest subarray, so earliest index matters
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, -1, 1, 1};
    long long k = 3;

    cout << "Brute: " << longestSubarrayBrute(arr, k) << endl;
    cout << "Better: " << longestSubarrayBetter(arr, k) << endl;
    cout << "Optimal: " << longestSubarrayWithSumK(arr, k) << endl;

    return 0;
}
