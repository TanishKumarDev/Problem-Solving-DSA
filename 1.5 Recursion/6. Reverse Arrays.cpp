// Problem Statement: Reverse an array, You are given a string s. Your task is to determine if the string is a palindrome. A string is considered a palindrome if it reads the same forwards and backwards.
// https://www.geeksforgeeks.org/problems/palindrome-string0817/1

// Examples :

// Input: s = "abba"
// Output: true

// Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.
#include <bits/stdc++.h>
using namespace std;

// Function to print the array
void printArray(const int arr[], int n) {
    if (arr == nullptr || n == 0) {
        cout << "Array is empty or null." << endl;
        return;
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Approach 1: Reverse using Brute Force
// Intuition:
// - Create a new array and copy elements from the input array in reverse order.
// - This is a straightforward method that preserves the original array but requires extra space.
// - It is simple to implement and useful for understanding the problem, but not ideal for memory-constrained scenarios.
// Time Complexity: O(n), Space Complexity: O(n)
void reverseBrute(const int arr[], int n, int ans[]) {
    if (arr == nullptr || n == 0) return; // Edge case: null or empty array
    for (int i = n - 1; i >= 0; i--) {
        ans[n - 1 - i] = arr[i];
    }
}

// Approach 2: Reverse using Recursion
// Intuition:
// - Recursively swap elements from the start and end of the array, moving inward until the pointers meet.
// - This approach leverages the call stack to manage the reversal process, making the code concise.
// - It is elegant but may not be suitable for very large arrays due to recursion stack space.
// Time Complexity: O(n), Space Complexity: O(n/2) due to recursion stack
void reverseRecursive(int arr[], int start, int end) {
    if (arr == nullptr || start >= end) return; // Edge case: null or no swaps needed
    swap(arr[start], arr[end]);
    reverseRecursive(arr, start + 1, end - 1);
}

// Approach 3 Optimal: Reverse using Two Pointers
// Intuition:
// - Use two pointers starting at opposite ends of the array and swap elements while moving toward the center.
// - This method is efficient as it operates in-place, requiring no extra space.
// - It is the most practical approach for most scenarios due to its simplicity and minimal resource usage.
// Time Complexity: O(n), Space Complexity: O(1)
void reverseTwoPointers(int arr[], int n) {
    if (arr == nullptr || n <= 1) return; // Edge case: null, empty, or single element
    int left = 0, right = n - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Approach 4: Reverse using Library Method
// Intuition:
// - Utilize the standard library's reverse function to perform the reversal in-place.
// - This approach is concise and leverages optimized library code, reducing the chance of implementation errors.
// - It is ideal when code simplicity and reliability are prioritized over custom implementation.
// Time Complexity: O(n), Space Complexity: O(1)
void reverseLibrary(int arr[], int n) {
    if (arr == nullptr || n == 0) return; // Edge case: null or empty array
    reverse(arr, arr + n);
}
int main() {
    // Test Case 1: Standard array
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseBrute(arr, n, arr);
    cout << "Reversed using Brute Force: ";
    printArray(arr, n);

    reverseRecursive(arr, 0, n - 1);
    cout << "Reversed using Recursion: ";
    printArray(arr, n);

    reverseTwoPointers(arr, n);
    cout << "Reversed using Two Pointers: ";
    printArray(arr, n);

    reverseLibrary(arr, n);
    cout << "Reversed using Library Method: ";
    printArray(arr, n);



    return 0;
}