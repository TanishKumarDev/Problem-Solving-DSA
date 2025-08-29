#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: LeetCode 268 - Missing Number 
// https://leetcode.com/problems/missing-number/
// Problem Statement: Given an array nums containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array.
// Example:
// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers in range [0,3] = {0,1,2,3}.
// 2 is missing as it is not in nums.
// Constraints:
// - n == nums.length
// - 1 <= n <= 10^4
// - 0 <= nums[i] <= n
// - All numbers in nums are unique.

// 🔴 Approach 1: Brute Force
// Intuition: Check each number from 0 to n to see if it exists in the array.
// If a number is not found, it is the missing number.
// Algo:
// 1. Iterate through numbers from 0 to n.
// 2. For each number i, check if it exists in nums by iterating through the array.
// 3. If i is not found, return i as the missing number.
// 4. If no number is missing, return -1 (should not occur per constraints).
// TC: O(n^2) - For each number from 0 to n (n+1 iterations), we scan the array (n iterations).
// SC: O(1) - No extra space used except for variables.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();  // number of elements

        // Check every number from 0 to n
        for (int i = 0; i <= n; i++) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) return i; // return first missing
        }
        return -1; // should never reach per constraints
    }
};

// 🔵 Approach 2: Better (Using Hash Array)
// Intuition: Use a hash array to mark the presence of numbers from 0 to n.
// The index with no mark indicates the missing number.
// Algo:
// 1. Create a hash array of size n+1 initialized to 0.
// 2. Mark each number in nums by setting hash[nums[i]] = 1.
// 3. Iterate through hash array; the first index with value 0 is the missing number.
// 4. If none found, return -1 (should not occur).
// TC: O(n) - One pass to mark hash (O(n)), one pass to find missing (O(n)).
// SC: O(n) - Hash array of size n+1.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        vector<int> hash(n + 1, 0); // hash array to mark presence

        for (int i = 0; i < n; i++) {
            hash[nums[i]] = 1; // mark number as present
        }
        for (int i = 0; i <= n; i++) {
            if (hash[i] == 0) return i; // missing number
        }
        return -1; // should never reach
    }
};

// 🟢 Approach 3: Optimal (Sum Difference)
// Intuition: The array should contain numbers 0 to n. Compute the expected sum of numbers
// from 0 to n using the formula n*(n+1)/2, subtract the sum of array elements.
// The difference is the missing number.
// Algo:
// 1. Calculate expected sum = n*(n+1)/2 (use long long to avoid overflow).
// 2. Calculate sum of array elements.
// 3. Return expected_sum - array_sum as the missing number.
// TC: O(n) - One pass to compute array sum.
// SC: O(1) - Only variables used.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        long long expected_sum = (long long)n * (n + 1) / 2; // sum of 0 to n
        
        long long array_sum = 0;
        for (int i = 0; i < n; i++) {
            array_sum += nums[i]; // sum of array elements
        }
        
        return expected_sum - array_sum; // missing number
    }
};

// 🟢 Approach 4: Optimal (XOR)
// Intuition: XOR all numbers from 0 to n with all array elements.
// Since a^a=0, paired numbers cancel out, leaving the missing number.
// Algo:
// 1. Compute xor1 = 0^1^2^...^n (all numbers in range).
// 2. Compute xor2 = nums[0]^nums[1]^...^nums[n-1] (array elements).
// 3. Return xor1 ^ xor2, which gives the missing number.
// TC: O(n) - Two passes: one for range, one for array.
// SC: O(1) - Only variables used.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        // xor1 = 0 ^ 1 ^ 2 ^ ... ^ n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }

        // xor2 = nums[0] ^ nums[1] ^ ... ^ nums[n-1]
        for (int i = 0; i < n; i++) {
            xor2 ^= nums[i];
        }

        // Missing number = xor1 ^ xor2
        return xor1 ^ xor2;
    }
};