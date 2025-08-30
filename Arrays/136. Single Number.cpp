#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : LeetCode 136 - Single Number
// Problem Statement: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.
// Example: 
// Input: nums = [2,2,1]
// Output: 1
// Explanation: 2 appears twice, 1 appears once.
// Constraint: 
// - 1 <= nums.length <= 3 * 10^4
// - -3 * 10^4 <= nums[i] <= 3 * 10^4
// - Each element in the array appears twice except for one element which appears only once.

// 🔴 Approach 1 Brute Force : Counting Occurrences
// Intuition : Check each element's count in the array. The one with count 1 is the single number.
// Algo :
// 1. For each element nums[i], iterate through the array and count occurrences.
// 2. If count == 1, return nums[i].
// TC : O(n^2) - Nested loops: outer O(n), inner O(n).
// SC : O(1) - No extra space, only variables.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int count = 0;  // reset for each element
            for(int j = 0; j < n; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }
            if(count == 1) {
                return nums[i];
            }
        }
        return -1; // should never happen if input is valid
    }
};

// 🔵 Approach 2 Better : Hashing with Frequency Array (assuming non-negative numbers)
// Intuition : Use a frequency array to count occurrences. The index with count 1 is the single number.
// Algo :
// 1. Find max element to size the hash array.
// 2. Count frequencies in hash.
// 3. Iterate array, return nums[i] if hash[nums[i]] == 1.
// TC : O(n) - Two passes: one for counting, one for finding.
// SC : O(maxi + 1) - Frequency array sized to max element.
// Limitation: Assumes non-negative numbers; fails for negatives.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> hash(maxi + 1, 0);

        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }
        
        for(int i=0; i<n; i++){
            if(hash[nums[i]] == 1)
            return nums[i];
        }

        return -1;
    }
};

// 🔵 Approach 3 Better : Using Unordered Map for Frequency
// Intuition : Use unordered_map to count frequencies, handling negative numbers.
// Algo :
// 1. Insert all elements into map with frequency.
// 2. Iterate map, return key with freq == 1.
// TC : O(n) average - Hash map insertions and traversal.
// SC : O(n) - Map stores up to n unique elements.
// Works for negatives and large ranges.
class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }
        for (auto& p : mp) {
            if (p.second == 1) {
                return p.first;
            }
        }
        return -1; // just in case
    }
};

// 🟢 Approach 4 Optimal: XOR All Elements
// Intuition : XOR cancels duplicates (x ^ x = 0), leaves single number (x ^ 0 = x).
// Algo :
// 1. Initialize ans = 0.
// 2. XOR all elements: ans ^= x for each x in nums.
// 3. Return ans.
// TC : O(n) - Single pass to XOR all elements.
// SC : O(1) - Only variables used.
// Works with negatives, no overflow issues.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            ans ^= x; // XOR cancels duplicates
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}