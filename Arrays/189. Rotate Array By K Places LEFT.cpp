#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: LEFT Rotate an Array by K Places
// Given an array of size `n`, rotate it to the left by `k` positions.

// Example:
// Input : arr = [1, 2, 3, 4, 5, 6, 7], k = 2
// Output: arr = [3, 4, 5, 6, 7, 1, 2]

// 🔴 Approach 1: Brute Force using Extra Array
// TC: O(n), SC: O(k)
void leftRotateBrute(vector<int>& arr, int k) {
    int n = arr.size();
    if (n <= 1 || k == 0) return;

    k %= n; // Handle k > n
    vector<int> temp(k);

    // Store first k elements
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    // Shift remaining elements to the left
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    // Place stored elements at the end
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

// 🔵 Approach 2: Optimal using Reversal Algorithm
// TC: O(n), SC: O(1)
void leftRotateOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0 || k == 0) return;

    k %= n;

    // Step 1: Reverse first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Step 2: Reverse remaining n-k elements
    reverse(arr.begin() + k, arr.end());

    // Step 3: Reverse entire array
    reverse(arr.begin(), arr.end());
}

// 🔧 Utility Function to Print Array
void printArray(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}

// 🧪 Driver Code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original Array: ";
    printArray(arr);

    // Use any one approach
    // leftRotateBrute(arr, k);
    leftRotateOptimal(arr, k);

    cout << "Array after Left Rotation by " << k << ": ";
    printArray(arr);

    return 0;
}
