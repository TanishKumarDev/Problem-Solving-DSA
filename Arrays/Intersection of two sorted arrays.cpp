#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Intersection of Two Sorted Arrays
// https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1
// Problem Statement: Given two sorted arrays arr1[] and arr2[], return the intersection of both arrays.
// The intersection contains elements common to both arrays, with no duplicates, in ascending order.
// If no common elements exist, return an empty array.
// Examples:
// - Input: arr1 = [1,2,3,4], arr2 = [2,4,6,7,8]
//   Output: [2,4]
//   Explanation: 2 and 4 are common elements.
// - Input: arr1 = [1,2,2,3,4], arr2 = [2,2,4,6,7,8]
//   Output: [2,4]
//   Explanation: 2 and 4 are common, duplicates ignored.
// - Input: arr1 = [1,2], arr2 = [3,4]
//   Output: []
//   Explanation: No common elements.
// Constraints:
// - 1 ≤ arr1.size(), arr2.size() ≤ 10^5
// - 1 ≤ arr1[i], arr2[i] ≤ 10^6

// 🔴 Approach 1: Using Set
// Intuition: Store arr1 in a set to remove duplicates and enable O(log n) lookup.
// Check arr2 elements against the set, adding common elements to result while skipping duplicates.
// Algo:
// 1. Create a set from arr1 (removes duplicates automatically).
// 2. Iterate through arr2; if an element exists in the set and isn't the last added to result, add it.
// 3. Return result vector.
// TC: O(n log n + m log n)
// - Building set: O(n log n) for n elements.
// - Checking arr2: O(m log n) for m lookups.
// SC: O(n) for set storing unique elements of arr1, plus O(min(n,m)) for result.
class Solution {
public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        set<int> s(arr1.begin(), arr1.end()); // Create set from arr1 to store unique elements
        vector<int> result; // Store intersection
        for (int x : arr2) {
            // Check if x is in set and not a duplicate in result
            if (s.count(x) && (result.empty() || result.back() != x)) {
                result.push_back(x); // Add common element
            }
        }
        return result; // Return intersection
    }
};

// 🟡 Approach 2: Using Map
// Intuition: Use a map to store frequencies of arr1 elements, then check arr2 for common elements,
// ensuring no duplicates in result.
// Algo:
// 1. Create a map to store frequency of arr1 elements.
// 2. Iterate through arr2; if an element exists in map (freq > 0) and isn't the last added to result, add it.
// 3. Return result vector.
// TC: O(n log n + m log n)
// - Building map: O(n log n) for n elements.
// - Checking arr2: O(m log n) for m lookups.
// SC: O(n) for map storing unique elements of arr1, plus O(min(n,m)) for result.
class Solution {
public:
    vector<int> intersection(vector<int> &arr2, vector<int> &arr1) {
        map<int, int> mp; // Map to store frequency of arr1 elements
        for (int x : arr1) mp[x]++; // Count frequencies
        vector<int> result; // Store intersection
        for (int x : arr2) {
            // Check if x exists in map and not a duplicate in result
            if (mp[x] > 0 && (result.empty() || result.back() != x)) {
                result.push_back(x); // Add common element
            }
        }
        return result; // Return intersection
    }
};

// 🟢 Approach 3: Two Pointers (Optimal)
// Intuition: Since arrays are sorted, use two pointers to traverse both arrays, comparing elements.
// Add common elements to result, skip duplicates by checking last added element.
// Algo:
// 1. Initialize pointers i (for arr1) and j (for arr2) to 0, and result vector.
// 2. While i < n and j < m:
//    - If arr1[i] == arr2[j]: Add to result if not duplicate, increment i, j.
//    - If arr1[i] < arr2[j]: Increment i (skip non-common).
//    - Else: Increment j.
// 3. Return result vector.
// TC: O(n + m) - Linear traversal of both arrays.
// SC: O(min(n,m)) - Only result vector, no extra data structure.
class Solution {
public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(), m = arr2.size();
        vector<int> result; // Store intersection
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (arr1[i] == arr2[j]) { // Common element found
                if (result.empty() || result.back() != arr1[i]) {
                    result.push_back(arr1[i]); // Add if not duplicate
                }
                i++; j++; // Move both pointers
            } else if (arr1[i] < arr2[j]) {
                i++; // Skip smaller element in arr1
            } else {
                j++; // Skip smaller element in arr2
            }
        }
        return result; // Return intersection
    }
};
