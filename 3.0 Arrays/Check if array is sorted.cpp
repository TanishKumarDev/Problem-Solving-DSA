#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach to check if array is sorted
bool isSortedBrute(int arr[], int n) {
    // Time Complexity: O(n^2) - Nested loops comparing all pairs
    // Space Complexity: O(1) - No extra space used
    // Intuition: Compare each element with all subsequent elements
    // If any element is found to be greater than a later element, array isn't sorted
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // For ascending order check (for descending, use '>')
            if (arr[j] < arr[i]) {
                return false; // Found a violation of sorting order
            }
        }
    }
    return true; // No violations found
}

// Optimal Approach to check if array is sorted
bool isSortedOptimal(int arr[], int n) {
    // Time Complexity: O(n) - Single pass through array
    // Space Complexity: O(1) - No extra space used
    // Intuition: Just compare each element with its immediate neighbor
    // More efficient than brute force as it makes minimum necessary comparisons
    
    for (int i = 1; i < n; i++) { // Start from 1 to compare with previous
        if (arr[i] < arr[i - 1]) { // For ascending order
            return false; // Found a violation
        }
        
        // For descending order check, we would use:
        // if (arr[i] > arr[i - 1]) return false;
    }
    return true; // All elements in order
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5}; // Sorted ascending
    int arr2[] = {5, 4, 3, 2, 1}; // Sorted descending
    int arr3[] = {1, 3, 2, 4, 5}; // Unsorted
    int n = 5;
    
    // Testing brute force approach
    cout << "Brute Force Results:" << endl;
    cout << "Array 1: " << (isSortedBrute(arr1, n) ? "True" : "False") << endl;
    cout << "Array 2: " << (isSortedBrute(arr2, n) ? "True" : "False") << endl;
    cout << "Array 3: " << (isSortedBrute(arr3, n) ? "True" : "False") << endl << endl;
    
    // Testing optimal approach
    cout << "Optimal Results:" << endl;
    cout << "Array 1: " << (isSortedOptimal(arr1, n) ? "True" : "False") << endl;
    cout << "Array 2: " << (isSortedOptimal(arr2, n) ? "True" : "False") << endl;
    cout << "Array 3: " << (isSortedOptimal(arr3, n) ? "True" : "False") << endl;
    
    return 0;
}