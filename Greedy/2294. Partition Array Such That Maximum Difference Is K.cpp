#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : 2294. Partition Array Such That Maximum Difference Is K
// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/?envType=daily-question&envId=2025-06-19

// You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.
// Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Example : 
// Input: nums = [3,6,1,2,5], k = 2
// Output: 2
// Explanation:
// We can partition nums into the two subsequences [3,1,2] and [6,5].
// The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
// The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
// Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.

// 🔴 Approach 1 Brute Force : 
// Intuition :
// Algo :
// TC :
// SC :

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal: (Greedy + Sorting)
// Intuition :
// 1. we need to generate subsequences(1 or more can be) -- but here is the catch
// 2. we need to generate the subsequence such that the maximum difference between the elements in the subsequence is 'at most k'.
// 2.1 this means we need to bring the elements in the subsequence as close to each other as possible. to get the maximum difference of 'k' between the elements in the subsequence.
// 2.2 we can do this by sorting the array and then selecting the elements in the subsequence such that the difference between the elements is "at most k".
// another twist "You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences." means we can't take one element from more than one or we can se occur in multiple subsequences. 
// 3.1 we can do this by iterating the array and keeping track of the start of the current group.
// 3.2 we can start a new group when the difference between the current element and the start of the group is greater than 'k'.
// 3.3 we can increment the count when we start a new group.
// 3.4 we can return the count.

// Algo :
// Sort the array
// Initialize count = 1 (at least one subsequence)
// Start iterating:
// Keep track of start of the current group
// If nums[i] - start > k, start a new group
// Increment count
// Return count

// TC: O(n log n) sorting
// SC: O(1) in place

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 1; // at least one subsequence
        int start = nums[0]; // start of the current group

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - start > k) {  // if the difference between the current element and the start of the group is greater than 'k'
                count++; // then we need to start a new group and increment the count
                start = nums[i]; // start of the new group
            }
        }

        return count;
    }
};

int main()
{
    
    return 0;
}