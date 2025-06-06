/**

 * Problem: Reverse an array in-place
 * Example: [1, 2, 3, 4, 5] -> [5, 4, 3, 2, 1]
 * 
 * Approaches:
 * 1. Recursive Two-Pointer Approach
 * 2. Iterative Two-Pointer Approach
 * 3. Using Stack (Extra Space)
 * 
 * Intuition:
 * - We can reverse array by swapping elements from both ends
 * - For array of length n, we need n/2 swaps
 * - Each swap brings one element to its correct position
 * - Process continues until we reach the middle
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Recursive Two-Pointer Approach
 * - Uses two pointers (left and right) moving toward center
 * - Swaps elements at both pointers in each recursive call
 * - Modifies array in-place
 * 
 * TC: O(n/2) = O(n) - Makes n/2 recursive calls
 * SC: O(n/2) = O(n) - Recursion stack space
 */
void reverseArrayRecursive(vector<int> &arr, int l, int r) {
    // Base case: when left pointer crosses or meets right pointer
    if (l >= r) return;

    // Swap elements at positions l and r
    swap(arr[l], arr[r]);

    // Recursive call moving pointers toward center
    reverseArrayRecursive(arr, l + 1, r - 1);
}

/**
 * Approach 2: Iterative Two-Pointer Approach
 * - Uses while loop instead of recursion
 * - More space efficient
 * - Same logic as recursive approach
 * 
 * TC: O(n/2) = O(n) - Makes n/2 swaps
 * SC: O(1) - Constant space
 */
void reverseArrayIterative(vector<int> &arr) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

/**
 * Approach 3: Using Stack (Extra Space)
 * - Uses stack to store elements temporarily
 * - Not in-place, uses extra space
 * - Demonstrates alternative approach
 * 
 * TC: O(n) - Two passes through array
 * SC: O(n) - Extra space for stack
 */
vector<int> reverseArrayStack(vector<int> arr) {
    stack<int> st;
    // Push all elements to stack
    for (int x : arr) {
        st.push(x);
    }
    // Pop elements to get reversed array
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = st.top();
        st.pop();
    }
    return arr;
}

// Helper function to print array
void printArray(const vector<int> &arr, const string &prefix = "") {
    cout << prefix;
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// 🎯 Driver Function
int main() {
    // Test array
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    printArray(arr);
    
    // Approach 1: Recursive
    vector<int> arr1 = arr;  // Create copy for testing
    reverseArrayRecursive(arr1, 0, arr1.size() - 1);
    cout << "\nApproach 1 - Recursive Two-Pointer:" << endl;
    printArray(arr1, "Reversed array: ");
    
    // Approach 2: Iterative
    vector<int> arr2 = arr;  // Create copy for testing
    reverseArrayIterative(arr2);
    cout << "\nApproach 2 - Iterative Two-Pointer:" << endl;
    printArray(arr2, "Reversed array: ");
    
    // Approach 3: Stack
    vector<int> arr3 = reverseArrayStack(arr);
    cout << "\nApproach 3 - Using Stack:" << endl;
    printArray(arr3, "Reversed array: ");
    
    return 0;
}

/**
 * Additional Notes:
 * 1. Two-Pointer Technique:
 *    - Very efficient for in-place operations
 *    - Common pattern in array manipulation
 *    - Works for both even and odd length arrays
 * 
 * 2. Recursive vs Iterative:
 *    - Iterative is more space efficient (O(1) vs O(n))
 *    - Both have same time complexity O(n)
 *    - Recursive is more elegant but can cause stack overflow for large arrays
 * 
 * 3. Edge Cases:
 *    - Empty array: no operation needed
 *    - Single element: no operation needed
 *    - Even length: pointers meet at middle
 *    - Odd length: pointers cross at middle
 * 
 * 4. Applications:
 *    - String reversal
 *    - Palindrome checking
 *    - Array rotation
 *    - Two-pointer problems
 */ 