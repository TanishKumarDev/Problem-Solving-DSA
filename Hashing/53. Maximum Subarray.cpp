#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Maximum Subarray
// Given an integer array nums, find the contiguous subarray (containing at least one number) with the largest sum and return its sum.
// If all subarray sums are negative, return 0 (assuming empty subarray is valid with sum 0).

// Example: 
// Input: arr = [-2, -3, 4, -1, -2, 1, 5, -3], n = 8
// Output: 7 (subarray [4, -1, -2, 1, 5])

// Constraints: 
// - 1 <= arr.length <= 10^5
// - -10^4 <= arr[i] <= 10^4

// 🔴 Brute Force: Check All Subarrays
// Intuition:
// Bhai, imagine you’re at a buffet, and you want the plate with the maximum tastiness (sum). You try every possible combination of dishes (subarrays) by picking a start and end point, adding up their flavors (elements), and keeping track of the best combo. If all dishes are bland (negative sum), you just walk away (return 0).

// Algo:
// 1. Loop through all possible start indices i (0 to n-1).
// 2. For each i, loop through all possible end indices j (i to n-1).
// 3. Calculate the sum of elements from i to j.
// 4. Update maxSum if the current sum is larger.
// 5. Return maxSum if non-negative, else 0.

// TC: O(n^3) — triple nested loops (two for selecting subarray, one for summing).
// SC: O(1) — just a few variables, no extra space.

// 📌 Note: Difference Between j = 0 vs j = i in Brute Force
// - j = i: ✅ Starts from i, only considering valid subarrays (j >= i), like picking dishes in order.
//          ⏱️ Correct approach, avoids invalid subarrays.
// - j = 0: ❌ Would include invalid subarrays (j < i), like eating dessert before the main course—makes no sense.
// - Final Verdict: j = i is necessary for correct subarray selection; j = 0 breaks the logic.

long long maxSubArrayBrute(vector<int>& arr) {
    int n = arr.size();
    long long maxSum = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum < 0 ? 0 : maxSum;
}

// 🟡 Better: Optimized Brute with Prefix Sum
// Intuition:
// Ab thodi akal lagate hain, bhai! Instead of adding the same dishes (elements) repeatedly for each subarray, keep a running total as you extend the subarray. It’s like eating one dish at a time and checking if the current combo is tastier than the last. Still checking all start-end combos, but smarter about summing.

// Algo:
// 1. Loop through all possible start indices i (0 to n-1).
// 2. For each i, maintain a running sum from i to j (j from i to n-1).
// 3. Update maxSum if the current sum is larger.
// 4. Return maxSum if non-negative, else 0.

// TC: O(n^2) — two nested loops (start and end indices).
// SC: O(1) — only a few variables, no extra space.

long long maxSubArrayBetter(vector<int>& arr) {
    int n = arr.size();
    long long maxSum = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum < 0 ? 0 : maxSum;
}

// 🟢 Optimal: Kadane’s Algorithm
// Intuition:
// Yeh hai asli game-changer, bhai! Imagine you’re eating dishes one by one, keeping a running score of tastiness. If the score goes negative, ditch the current combo and start fresh from the next dish. At each step, you check if the current combo is the tastiest so far. It’s like finding the best streak in one go, no need to check every combo!

// Algo:
// 1. Initialize sum = 0 (current subarray sum) and maxSum = LLONG_MIN.
// 2. Iterate through the array:
//    - Add current element to sum.
//    - Update maxSum if sum is larger.
//    - If sum < 0, reset sum to 0 (start a new subarray).
// 3. Return maxSum if non-negative, else 0.

// TC: O(n) — single pass through the array.
// SC: O(1) — only a few variables.

long long maxSubArrayKadane(vector<int>& arr) {
    int n = arr.size();
    long long sum = 0, maxSum = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxSum < 0 ? 0 : maxSum;
}

// 🟢 Follow-Up: Print Subarray with Maximum Sum
// Intuition:
// Kadane ka bada bhai! Same vibe as Kadane’s, but now you also track which dishes (indices) gave the best taste (max sum). Keep a temporary start index, and update the start-end indices whenever you find a better sum. It’s like noting down the exact combo of dishes that made your meal epic.

// Algo:
// 1. Initialize sum = 0, maxSum = LLONG_MIN, start = -1, end = -1, tempStart = 0.
// 2. Iterate through the array:
//    - Add current element to sum.
//    - If sum > maxSum, update maxSum, set start = tempStart, end = current index.
//    - If sum < 0, reset sum to 0 and update tempStart to next index.
// 3. Return {maxSum, {start, end}} if maxSum non-negative, else {0, {}}.

// TC: O(n) — single pass through the array.
// SC: O(1) — only a few variables (excluding output vector).

pair<long long, vector<int>> maxSubArrayPrint(vector<int>& arr) {
    int n = arr.size();
    long long sum = 0, maxSum = LLONG_MIN;
    int start = -1, end = -1, tempStart = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > maxSum) {
            maxSum = sum;
            start = tempStart;
            end = i;
        }
        if (sum < 0) {
            sum = 0;
            tempStart = i + 1;
        }
    }
    if (maxSum < 0) {
        return {0, {}};
    }
    return {maxSum, {start, end}};
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Brute: " << maxSubArrayBrute(arr) << endl;
    cout << "Better: " << maxSubArrayBetter(arr) << endl;
    cout << "Kadane: " << maxSubArrayKadane(arr) << endl;
    auto result = maxSubArrayPrint(arr);
    cout << "Print Subarray: Sum = " << result.first << ", Indices = [" << result.second[0] << ", " << result.second[1] << "]" << endl;
    return 0;
}