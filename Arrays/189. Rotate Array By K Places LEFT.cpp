#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: LEFT Rotate an Array by K Places
// Given an array of size `n`, rotate it to the left by `k` positions.

// Example:
// Input : arr = [1, 2, 3, 4, 5, 6, 7], k = 2
// Output: arr = [3, 4, 5, 6, 7, 1, 2]

// 🔴 Approach 1: Brute Force using Extra Array
// Intuition:
// Store first k elements in a temp array,
// shift rest to the front, then put temp at the back.

// TC: O(n)
// SC: O(k)
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
// Intuition:
// 1. Reverse first k elements
// 2. Reverse remaining n-k elements
// 3. Reverse the entire array

// TC: O(n)
// SC: O(1)
void reversePart(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start++], arr[end--]);
    }
}

void leftRotateOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    if (n <= 1 || k == 0) return;

    k %= n; // Normalize rotation

    reversePart(arr, 0, k - 1);     // Reverse first k
    reversePart(arr, k, n - 1);     // Reverse rest
    reversePart(arr, 0, n - 1);     // Reverse whole
}

// 🔍 Utility: Print array
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n";
}

// 🧪 Driver Code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original Array: ";
    printArray(arr);

    // Call any one approach
    // leftRotateBrute(arr, k);
    leftRotateOptimal(arr, k);

    cout << "Array after Left Rotation by " << k << ": ";
    printArray(arr);

    return 0;
}
