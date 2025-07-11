#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Majority Element
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊n/2⌋ times.
// You may assume that the majority element always exists in the array.

// Example: 
// Input: arr = [2,2,3,2,3,1,2], n = 7
// Output: 2

// Constraints: 
// - 1 <= n <= 10^5
// - The majority element always exists in the array.

// 🔴 Brute Force: Linear Search
// Intuition:
// Check each element's frequency by counting its occurrences in the array.
// If any element appears more than n/2 times, it is the majority element.

// Algo:
// 1. Iterate through each element in the array.
// 2. For each element, count its occurrences by scanning the array.
// 3. If the count exceeds n/2, return that element.
// 4. If no such element is found, return -1.

// TC: O(n^2) — nested loops to count frequency for each element.
// SC: O(1) — only a constant amount of extra space.

int majorityElementBrute(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > n/2) return arr[i];
    }
    return -1;
}
// 📌 Note: 
// - Difference Between j = 0 vs j = i in Brute Force Count
// - j = i: ✅ Counts nums[i] from index i to n-1, skipping earlier indices to avoid recounting.
//          ⏱️ Slight optimization: reduces unnecessary comparisons for already checked values.
//          🧠 Useful when checking only new/unvisited elements.
// - j = 0: ❌ Counts nums[i] in the entire array (0 to n-1), recomputing frequencies.
//          ⏳ Less efficient due to repeated work for previously visited values.
// - Final Verdict: Both give correct results. Use j = i for slight optimization when exiting early is allowed; j = 0 is simpler to read.


// 🟠 Better: Hashing
// Intuition:
// Use a hash map to store the frequency of each element in one pass.
// Then, check which element has a frequency greater than n/2.

// Algo:
// 1. Create a hash map to store element frequencies.
// 2. Iterate through the array, incrementing the count of each element in the hash map.
// 3. Iterate through the hash map to find an element with frequency > n/2.
// 4. Return that element, or -1 if none found.

// TC: O(n) — single pass to build hash map and a pass through the map (average case).
// SC: O(n) — hash map may store up to n/2 unique elements.

int majorityElementHashing(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[arr[i]]++;
    }
    for (auto it : map) {
        if (it.second > n/2) return it.first;
    }
    return -1;
}

// 🟢 Optimal: Moore’s Voting Algorithm
// Intuition:
// Since the majority element appears more than n/2 times, it will "outvote" all other elements.
// Track a candidate and count; if count reaches 0, pick a new candidate.
// Verify the candidate at the end to ensure it’s the majority.

// Algo:
// 1. Initialize count = 0 and candidate = -1.
// 2. Iterate through the array:
//    - If count == 0, set candidate to current element and count = 1.
//    - If current element equals candidate, increment count.
//    - Otherwise, decrement count.
// 3. Verify the candidate by counting its occurrences.
// 4. If count > n/2, return candidate; otherwise, return -1.

// TC: O(n) — two passes through the array (one for voting, one for verification).
// SC: O(1) — only a few variables used.

int majorityElementMoore(vector<int>& arr) {
    int n = arr.size();
    int count = 0, candidate = -1;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) count++;
    }
    if (count > n/2) return candidate;
    return -1;
}

int main() {
    vector<int> arr = {2, 2, 3, 2, 3, 1, 2};
    cout << "Brute: " << majorityElementBrute(arr) << endl;
    cout << "Hashing: " << majorityElementHashing(arr) << endl;
    cout << "Moore: " << majorityElementMoore(arr) << endl;
    return 0;
}