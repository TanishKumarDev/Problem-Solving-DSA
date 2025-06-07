/**
 * Problem: Find all possible subsequences of an array that sum up to target value K
 * 
* Intuition:
 * - At each element, we have two choices:
 *   1. Include the element and add it to current sum
 *   2. Exclude the element and keep current sum
 * - We use backtracking to explore all possibilities
 * - When we reach end of array, we check if current sum equals K
 * - If yes, we add current subsequence to result
 * 
 * Time Complexity: O(2^n * n)
 * - For each element, we have 2 choices (include/exclude)
 * - Total 2^n subsequences possible
 * - Each subsequence can be up to n elements long
 * 
 * Space Complexity: O(n)
 * - Recursion stack depth is n (length of array)
 * - Additional space for storing results: O(2^n * n)
 * 
 * Example:
 * Array: [17, 18, 6, 11, 2, 4], K = 6
 * Possible subsequences with sum 6:
 * - [2, 4]
 * - [6]
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Recursive helper function to find all subsequences with sum K
 * @param ind Current index in array
 * @param sum Current sum of subsequence
 * @param k Target sum
 * @param cur Current subsequence being built
 * @param arr Input array
 * @param res Vector to store all valid subsequences
 */
void findSubsequence(int ind, int sum, int k, vector<int>& cur, vector<int>& arr, vector<vector<int>>& res) {
    int n = arr.size();

    // Base case: when we've processed all elements
    if (ind == n) {
        if (sum == k) {
            res.push_back(cur);
        }
        return;
    }

    // Choice 1: Exclude current element
    findSubsequence(ind + 1, sum, k, cur, arr, res);

    // Choice 2: Include current element
    cur.push_back(arr[ind]);
    findSubsequence(ind + 1, sum + arr[ind], k, cur, arr, res);

    // Backtrack: remove the last element to try other combinations
    cur.pop_back();
}

/**
 * Main function to find all subsequences with sum K
 * @param arr Input array
 * @param k Target sum
 * @return Vector of all valid subsequences
 */
vector<vector<int>> subsequencesSumK(vector<int>& arr, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    findSubsequence(0, 0, k, cur, arr, res);
    return res;
}

/**
 * ============================================
 * MAIN FUNCTION
 * ============================================
 */
int main() {
    // Test case
    vector<int> arr = {17, 18, 6, 11, 2, 4};
    int k = 6;

    vector<vector<int>> ans = subsequencesSumK(arr, k);

    // Print results
    cout << "Subsequences with sum = " << k << ":\n";
    for (auto seq : ans) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
