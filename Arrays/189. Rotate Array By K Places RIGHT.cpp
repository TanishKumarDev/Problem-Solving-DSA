#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Right Rotate an Array by K Places
// Example:
// Input : arr = [1, 2, 3, 4, 5], k = 2
// Output: arr = [4, 5, 1, 2, 3]

// 🔴 Approach 1: Brute Force
// Intuition:
// Rotate one step at a time, k times.

// Algorithm:
// 1. Repeat k times:
//    - Store last element.
//    - Shift all elements right.
//    - Place stored element at arr[0].

// Time Complexity: O(n * k)
// Space Complexity: O(1)

void rightRotateBrute(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    for (int r = 0; r < k; r++) {
        int last = arr[n - 1];
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }
}

// 🔵 Approach 2: Better using Extra Space
// Intuition:
// Copy last k elements and first n-k elements into a temp array.

// Time Complexity: O(n)
// Space Complexity: O(n)

void rightRotateBetter(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    vector<int> temp;

    // Copy last k elements
    for (int i = n - k; i < n; i++) {
        temp.push_back(arr[i]);
    }

    // Copy first n-k elements
    for (int i = 0; i < n - k; i++) {
        temp.push_back(arr[i]);
    }

    // Copy back to original
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

// 🟢 Approach 3: Optimal (Using Reversal)
// Intuition:
// 1. Reverse entire array.
// 2. Reverse first k elements.
// 3. Reverse rest n-k elements.

// Algorithm:
// Input: [1, 2, 3, 4, 5], k=2
// Step 1: reverse whole -> [5, 4, 3, 2, 1]
// Step 2: reverse first k -> [4, 5, 3, 2, 1]
// Step 3: reverse rest   -> [4, 5, 1, 2, 3]

// Time Complexity: O(n)
// Space Complexity: O(1)

void rightRotateOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0 || k == 0) return;

    k = k % n;  // Avoid overflow

    reverse(nums.begin(), nums.end());             // Reverse entire array
    reverse(nums.begin(), nums.begin() + k);       // Reverse first k elements
    reverse(nums.begin() + k, nums.end());         // Reverse remaining elements
}

// 🔍 Utility to Print Array
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// 🧪 Driver Code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    cout << "Original Array: ";
    printArray(arr);

    // rightRotateBrute(arr, k);
    // rightRotateBetter(arr, k);
    rightRotateOptimal(arr, k); // Best approach

    cout << "After Right Rotation by " << k << ": ";
    printArray(arr);

    return 0;
}
