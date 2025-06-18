#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Divide Array into Groups of 3 Where Max-Min ≤ k
// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2025-06-18
// Example: nums = [1,3,4,8,7,9,3,5,1], k = 2 → [[1,1,3],[3,4,5],[7,8,9]]
// Constraint: 
//   - Array length must be divisible by 3.
//   - Each group of 3 must have max-min difference ≤ k.
//   - If impossible, return empty array.

// 🔴 Approach 1 Brute Force:
// Intuition: Try every possible way to make groups of 3, like picking teams randomly and checking if they work. Too slow, bhai, like counting stars one by one!
// Algo: Generate all possible triplets, check if each triplet’s max-min ≤ k, and ensure all elements are used. Impractical for large arrays.
// TC: O(n!) - Factorial time, way too slow, like “ghar se nikalne mein saal lag jayega!”
// SC: O(n) - For recursion stack and storing triplets.

// 🔵 Approach 2 Better:
// Intuition: 
// Algo: 
// TC:
// SC:

// 🟢 Approach 3 Optimal:
// Intuition: Sort the array first, like lining up people by height, so nearby numbers are close. Then, pick groups of 3 next to each other. If any group’s max-min > k, it’s impossible, bhai!
// Algo: 
//   1. Check if array size is divisible by 3. If not, return empty. --> not necessary --> already give that " where n is a multiple of 3"
//   2. Sort the array to minimize differences.
//   3. Loop through array in steps of 3.
//   4. For each triplet, check if max-min > k. If so, return empty. --> invalid    
//   5. If valid, add triplet to result.
// TC: O(n log n) - Sorting takes the most time, rest is quick like 
// SC: O(n) - For output array (or O(log n) if output not counted, due to sorting stack).

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // Check if array size is divisible by 3
        int n = nums.size();
        // if (n % 3 != 0) {
        //     // Size not divisible by 3, no groups possible
        //     return {};
        // }
        
        // Sort array to group similar numbers together
        sort(nums.begin(), nums.end());
        
        // Initialize result to store triplets
        vector<vector<int>> result;
        
        // Loop through array in steps of 3
        for (int i = 0; i < n; i += 3) {
            // Check if triplet’s max-min ≤ k
            // Since sorted, nums[i+2] is max, nums[i] is min
            if (nums[i + 2] - nums[i] > k) {
                // Invalid triplet, return empty array
                return {};
            }
            // Valid triplet, add to result
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        
        // Return all valid triplets
        return result;
    }
};

int main() {
   
    Solution sol;
    
    // Test Case 1: Valid case
    // Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
    // Expected Output: [[1,1,3],[3,4,5],[7,8,9]]
    vector<int> nums1 = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    cout << "Test Case 1 (Valid case, k=2):\n";
    auto res1 = sol.divideArray(nums1, 2);
    for (auto& triplet : res1) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "] ";
    }
    cout << "\n\n";
    
    // Test Case 2: Invalid case
    // Input: nums = [1,3,4,8,7,9,3,5,1], k = 1
    // Expected Output: [] (No valid division)
    vector<int> nums2 = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    cout << "Test Case 2 (Invalid case, k=1):\n";
    auto res2 = sol.divideArray(nums2, 1);
    if (res2.empty()) cout << "[] (No valid division)\n\n";
    
    // Test Case 3: Empty input
    // Input: nums = [], k = 5
    // Expected Output: [] (Empty input)
    vector<int> nums3 = {};
    cout << "Test Case 3 (Empty input):\n";
    auto res3 = sol.divideArray(nums3, 5);
    if (res3.empty()) cout << "[] (Empty input)\n\n";
    
    // Test Case 4: Length not divisible by 3
    // Input: nums = [1,2,3,4], k = 1
    // Expected Output: [] (Length not divisible by 3)
    vector<int> nums4 = {1, 2, 3, 4};
    cout << "Test Case 4 (Length not divisible by 3):\n";
    auto res4 = sol.divideArray(nums4, 1);
    if (res4.empty()) cout << "[] (Length not divisible by 3)\n\n";

    return 0;
}