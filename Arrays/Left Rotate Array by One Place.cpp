#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Left Rotate Array by One Place
// Given an array of size `n`, rotate it to the left by one position.
// Example:
// Input : arr = [1, 2, 3, 4, 5]
// Output: arr = [2, 3, 4, 5, 1]

// 🔴 Approach 1: Brute Force
// Intuition:
// Create a temporary array and shift all elements to the left by one index.
// Place the first element at the end.

// Algorithm:
// 1. If array has 0 or 1 element, no rotation needed.
// 2. Create a temp array.
// 3. Copy elements with left shift.
// 4. Place first element at the end.
// 5. Copy back temp to original array.

// Time Complexity: O(n)
// Space Complexity: O(n)

void leftRotateBrute(vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || n == 1) return;

    vector<int> temp(n);
    for (int i = 1; i < n; i++) {
        temp[i - 1] = arr[i]; // shift left
    }
    temp[n - 1] = arr[0]; // move first element to end

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i]; // copy back to original array
    }
}

// 🔵 Approach 2: Better (In-Place)
// Intuition:
// Store the first element in a variable, shift all others to the left,
// and place the first element at the end.

// Algorithm:
// 1. Store arr[0] in a temp variable.
// 2. Shift elements from index 1 to n-1 left by 1 position.
// 3. Assign temp to arr[n-1].

// Time Complexity: O(n)
// Space Complexity: O(1)

void leftRotateBetter(vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || n == 1) return;

    int temp = arr[0]; // store first element
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i]; // shift each element left
    }
    arr[n - 1] = temp; // place first element at the end
}

// 🟢 Approach 3: Optimal using STL (rotate function)
// Intuition:
// Use C++ STL `rotate()` to rotate from `begin()` to `begin() + 1`

// Algorithm:
// Use std::rotate from algorithm header

// Time Complexity: O(n)
// Space Complexity: O(1)

void leftRotateOptimal(vector<int>& arr) {
    if (arr.size() <= 1) return;
    rotate(arr.begin(), arr.begin() + 1, arr.end());
}

// 🔍 Utility to print array
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// 🧪 Driver Code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original Array: ";
    printArray(arr);

    // Try one of the following:
    // leftRotateBrute(arr);
    // leftRotateBetter(arr);
    leftRotateOptimal(arr); // Best in practice

    cout << "After Left Rotation by 1: ";
    printArray(arr);

    return 0;
}
