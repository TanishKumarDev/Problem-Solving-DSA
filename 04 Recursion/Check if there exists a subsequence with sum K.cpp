/*
Problem: Check if there exists a subsequence with sum K
Approach: Use recursion to try all possible combinations of elements
Time Complexity: O(2^n) where n is the size of array
Space Complexity: O(n) due to recursion stack

The algorithm works by:
1. At each index, we have 2 choices:
   a) Include current element in sum
   b) Skip current element
2. Base case: When we reach end of array, check if sum equals K
3. Return true if any combination gives required sum
*/

#include <bits/stdc++.h>
using namespace std;

bool existsSubsequence(int ind, int sum, int K, vector<int>& arr) {
    // Base case: reached end of array
    if (ind == arr.size()) {
        return sum == K;  // Check if current sum equals target K
    }

    // Choice 1: pick the current element
    if (existsSubsequence(ind + 1, sum + arr[ind], K, arr)) {
        return true;
    }

    // Choice 2: skip the current element
    if (existsSubsequence(ind + 1, sum, K, arr)) {
        return true;
    }

    return false;
}

bool hasSubsequenceWithSumK(vector<int>& arr, int K) {
    return existsSubsequence(0, 0, K, arr);  // Start with index 0 and sum 0
}

int main() {
    vector<int> arr = {1, 2, 3};  // Example array
    int K = 5;  // Target sum

    if (hasSubsequenceWithSumK(arr, K)) {
        cout << "Yes, there exists a subsequence with sum " << K << endl;
    } else {
        cout << "No subsequence with sum " << K << " found." << endl;
    }

    return 0;
}
