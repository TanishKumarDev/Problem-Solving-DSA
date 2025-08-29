#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Union of Two Sorted Arrays (GeeksforGeeks)
// Problem Statement: Given two sorted arrays a[] and b[], each may contain duplicate elements,
// return the union of the two arrays in sorted order. The union is the set of distinct elements
// present in either array, with no duplicates.
// Examples:
// - Input: a = [1,2,3,4,5], b = [1,2,3,6,7]
//   Output: [1,2,3,4,5,6,7]
//   Explanation: Distinct elements from both arrays.
// - Input: a = [2,2,3,4,5], b = [1,1,2,3,4]
//   Output: [1,2,3,4,5]
//   Explanation: Duplicates (2 in a, 1 and 2 in b) appear once.
// - Input: a = [1,1,1,1,1], b = [2,2,2,2,2]
//   Output: [1,2]
//   Explanation: Only distinct elements 1 and 2.
// Constraints:
// - 1 ≤ a.size(), b.size() ≤ 10^5
// - -10^9 ≤ a[i], b[i] ≤ 10^9

// 🔴 Approach 1: Using Map
// Intuition: Use a map to store frequencies of elements from both arrays, then extract keys
// to get distinct elements in sorted order.
// Algo:
// 1. Create a map to store frequency of elements from a and b.
// 2. Iterate through a and b, incrementing frequency in map (handles duplicates).
// 3. Create result vector, push all map keys (sorted by map’s ordering).
// 4. Return result.
// TC: O((n1 + n2) log (n1 + n2))
// - Inserting n1 + n2 elements: O((n1 + n2) log (n1 + n2)) for map operations.
// - Extracting keys: O(k log k), where k is unique elements (≤ n1 + n2).
// SC: O(n1 + n2) for map storing unique elements, plus O(n1 + n2) for result.
class Solution {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        map<int, int> mp; // Map to store frequency of elements
        for (int x : a) mp[x]++; // Count frequencies from a
        for (int x : b) mp[x]++; // Count frequencies from b
        vector<int> result; // Store union
        for (auto& p : mp) {
            result.push_back(p.first); // Add distinct elements (sorted)
        }
        return result; // Return union
    }
};

// 🟡 Approach 2: Using Set
// Intuition: Use a set to store unique elements from both arrays, automatically handling duplicates,
// and get sorted order due to set’s properties.
// Algo:
// 1. Create a set to store unique elements.
// 2. Insert all elements from a and b into set (duplicates ignored).
// 3. Convert set to vector for result (sorted by set’s ordering).
// 4. Return result.
// TC: O((n1 + n2) log (n1 + n2))
// - Inserting n1 + n2 elements: O((n1 + n2) log (n1 + n2)) for set operations.
// - Converting to vector: O(k), where k is unique elements.
// SC: O(n1 + n2) for set storing unique elements, plus O(n1 + n2) for result.
class Solution {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> s; // Set to store unique elements
        for (int x : a) s.insert(x); // Insert elements from a
        for (int x : b) s.insert(x); // Insert elements from b
        vector<int> result(s.begin(), s.end()); // Convert set to sorted vector
        return result; // Return union
    }
};

// 🟢 Approach 3: Two Pointers (Optimal)
// Intuition: Since arrays are sorted, use two pointers to merge elements, picking the smaller value
// and skipping duplicates by checking the last added element in result.
// Algo:
// 1. Initialize pointers i (for a) and j (for b) to 0, and result vector.
// 2. While i < n1 and j < n2:
//    - If a[i] < b[j]: Add a[i] if not duplicate, increment i.
//    - If a[i] > b[j]: Add b[j] if not duplicate, increment j.
//    - If equal: Add one value, increment both i and j.
// 3. Add remaining elements from a or b, checking for duplicates.
// 4. Return result.
// TC: O(n1 + n2) - Linear traversal of both arrays.
// SC: O(n1 + n2) - Only result vector, no extra data structure.
class Solution {
public:
    // Function to return a list containing the union of the two sorted arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0;
        vector<int> res; // Final result to store union without duplicates

        // Traverse both arrays using two pointers
        while (i < n1 && j < n2) {
            int val;

            // Pick the smaller value
            if (a[i] < b[j]) {
                val = a[i++]; // Take from a, increment i
            } else if (a[i] > b[j]) {
                val = b[j++]; // Take from b, increment j
            } else {
                // If both are equal, take one and skip both
                val = a[i];
                i++; j++;
            }

            // Add only if it's not a duplicate of the last inserted
            if (res.empty() || res.back() != val) {
                res.push_back(val); // Add to result
            }
        }

        // Add remaining elements of array 'a', avoiding duplicates
        while (i < n1) {
            if (res.empty() || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
        }

        // Add remaining elements of array 'b', avoiding duplicates
        while (j < n2) {
            if (res.empty() || res.back() != b[j]) {
                res.push_back(b[j]);
            }
            j++;
        }

        return res; // Return the final union result
    }
};