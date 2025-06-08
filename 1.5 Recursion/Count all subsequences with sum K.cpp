/*
Problem: Count all subsequences with sum K
Given an array of integers and a target sum K, count all possible subsequences that sum to K.

Time Complexity: O(2^n) 
- For each element, we have 2 choices (include/exclude)
- This creates a binary tree of height n, resulting in 2^n nodes

Space Complexity: O(n)
- Maximum recursion stack depth is n (length of array)
- No extra space used besides recursion stack

Algorithm:
1. Use recursive approach to try all possible subsequences
2. For each element, we have two choices:
   - Include current element in subsequence
   - Exclude current element from subsequence
3. Keep track of current sum while building subsequences
4. When we reach end of array, check if sum equals target K

Intuition:
- Think of building subsequences by making include/exclude decisions for each element
- For each element arr[i], recursively try both:
  a) Skip arr[i] and continue with same sum
  b) Add arr[i] to sum and continue
- Base case: When we've processed all elements, check if sum equals K
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Recursive helper to count subsequences with sum K
 * @param ind Current index in array
 * @param sum Current sum of the subsequence
 * @param k Target sum
 * @param arr Input array
 * @return Count of valid subsequences from current index
 */
int countSubsequences(int ind, int sum, int k, vector<int>& arr) {
    int n = arr.size();

    // Base Case
    if (ind == n) {
        return (sum == k) ? 1 : 0; // Return 1 if sum equals K, else 0
    }

    // Exclude current element
    int exclude = countSubsequences(ind + 1, sum, k, arr); // Recursive call without current element

    // Include current element
    int include = countSubsequences(ind + 1, sum + arr[ind], k, arr); // Recursive call with current element

    return exclude + include; // Return sum of both paths
}

/**
 * Main function to count subsequences with sum K
 */
int main() {
    vector<int> arr = {17, 18, 6, 11, 2, 4};
    int k = 6;

    int count = countSubsequences(0, 0, k, arr);

    cout << "Number of subsequences with sum = " << k << ": " << count << endl;

    return 0;
}
