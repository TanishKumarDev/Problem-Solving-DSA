#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force: Generate all subarrays, check each sum
// Time Complexity: O(n^3), Space Complexity: O(1)
int longestSubarraySumKBrute(vector<int>& arr, long long K) {
    int n = arr.size();
    int maxLen = 0;

    // Try all subarrays from i to j
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = 0;

            // Compute sum of subarray arr[i..j]
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            // If sum == K, update max length
            if (sum == K) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// 🟡 Better: Remove inner loop by maintaining prefix sum in the middle loop
// Time Complexity: O(n^2), Space Complexity: O(1)
int longestSubarraySumKBetter(vector<int>& arr, long long K) {
    int n = arr.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;

        // Sum subarray from i to j
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == K) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// 🟠 Better: Prefix Sum + Hashing (Map) — handles negative numbers too
// Time Complexity: O(n log n) [due to map], Space Complexity: O(n)
int longestSubarraySumKHashing(vector<int>& arr, long long K) {
    int n = arr.size();
    long long sum = 0;
    int maxLen = 0;

    // Stores {prefix_sum : earliest_index}
    map<long long, int> preSumMap;
    preSumMap[0] = -1; // Important base case (empty subarray)

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: entire sum from 0 to i is K
        if (sum == K) {
            maxLen = max(maxLen, i + 1);
        }

        // Case 2: check if (sum - K) was seen before
        if (preSumMap.find(sum - K) != preSumMap.end()) {
            int prevIndex = preSumMap[sum - K];
            maxLen = max(maxLen, i - prevIndex);
        }

        // Store current sum if not already present (to maintain earliest index)
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

// 🟢 Optimal: Two-Pointer Sliding Window (ONLY when all elements are POSITIVE)
// Time Complexity: O(n), Space Complexity: O(1)
int longestSubarraySumKOptimal(vector<int>& arr, long long K) {
    int n = arr.size();
    int left = 0, right = 0, maxLen = 0;
    long long sum = 0;

    while (right < n) {
        sum += arr[right];

        // Shrink the window until sum <= K
        while (sum > K && left <= right) {
            sum -= arr[left];
            left++;
        }

        // Check if current window sum equals K
        if (sum == K) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }
    return maxLen;
}

// 🔹 Main Function to Test All Approaches
int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
    long long K = 6;

    cout << "🔴 Brute: " << longestSubarraySumKBrute(arr, K) << endl;
    cout << "🟡 Better (Prefix Sum): " << longestSubarraySumKBetter(arr, K) << endl;
    cout << "🟠 Better (Hashing): " << longestSubarraySumKHashing(arr, K) << endl;
    cout << "🟢 Optimal (Two Pointers): " << longestSubarraySumKOptimal(arr, K) << endl;

    return 0;
}
