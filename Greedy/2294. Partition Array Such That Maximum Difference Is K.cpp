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
// The brute-force idea is to try all possible groupings of the array into subsequences such that:
// Each element appears exactly once.
// The difference between max and min in each group ≤ k.
// But this is not feasible directly (𝑂(2ⁿ) or worse) because the number of ways to partition n elements into valid groups is combinatorially explosive.
// Instead, we can write a simplified brute-force simulation with greedy intent:

// Sort the array first to make "close numbers" sit together.
// Start from index 0, and create a greedy group of elements such that:
// max - min ≤ k for all elements in the group.
// If not, cut and start a new group.
//
// Algo :
// 1. Sort the array.
// 2. Initialize i = 0, count = 0
// 3. While i < n:
//    - Let start = nums[i]
//    - Let j = i
//    - While j < n and nums[j] - start ≤ k:
//        j++
//    - We’ve created one valid group → increment count
//    - Set i = j (next index after current group)
// 4. Return count
//
// TC: O(n log n) + O(n) = O(n log n)
// SC: O(1) in place
class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0, i = 0;

        while (i < n)
        {
            int start = nums[i];
            int j = i;
            while (j < n && nums[j] - start <= k)
            {
                j++;
            }
            count++;
            i = j; // next group starts
        }

        return count;
    }
};

    // Brute-like (Greedy Simulation)
    // Might check multiple elements in the inner while loop
    // Can be slightly slower due to more condition checks
    // Still O(n) in total after sorting, but with looser constants
    
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

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int count = 1;       // at least one subsequence
        int start = nums[0]; // start of the current group

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - start > k)
            {                    // if the difference between the current element and the start of the group is greater than 'k'
                count++;         // then we need to start a new group and increment the count
                start = nums[i]; // start of the new group
            }
        }

        return count;
    }
};
    // Optimal Solution
    // Only one pass of the array after sorting
    // Very tight logic, only one check per element

int main()
{
    // Notes



    return 0;
}