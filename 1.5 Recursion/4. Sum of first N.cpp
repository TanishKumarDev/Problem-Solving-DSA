/**
 * Approaches:
 * 1. Parameterized Recursion
 * 2. Non-Parameterized Recursion
 * 3. Functional Recursion (Return type)
 * 
 * Intuition:
 * - We can break down the sum into smaller subproblems
 * - For N=5: 1+2+3+4+5 = (1+2+3+4) + 5 = ((1+2+3) + 4) + 5 = ...
 * - Each recursive call handles one number and delegates rest to next call
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Parameterized Recursion
 * - Passes the sum as a parameter through each recursive call
 * - More functional programming style
 * - No global variables needed
 * 
 * TC: O(n) - Makes n recursive calls
 * SC: O(n) - Recursion stack space
 */
void sumOfN_param(int n, int sum) {
    // Base case: when n becomes 0, print the accumulated sum
    if (n < 1) {
        cout << "Parameterized Sum: " << sum << endl;
        return;
    }
    // Recursive call: add current number to sum and decrement n
    sumOfN_param(n - 1, sum + n);
}

/**
 * Approach 2: Non-Parameterized Recursion
 * - Uses a global variable to accumulate the sum
 * - More imperative programming style
 * - Note: Global variable needs to be reset if function called multiple times
 * 
 * TC: O(n) - Makes n recursive calls
 * SC: O(n) - Recursion stack space
 */
int sum_nonparam = 0;  // Global variable to store sum
void sumOfN_nonparam(int n) {
    // Base case: when n becomes 0, print the accumulated sum
    if (n < 1) {
        cout << "Non-Parameterized Sum: " << sum_nonparam << endl;
        return;
    }
    // Add current number to global sum
    sum_nonparam += n;
    // Recursive call with decremented n
    sumOfN_nonparam(n - 1);
}

/**
 * Approach 3: Functional Recursion (Return type)
 * - Returns the sum instead of printing it
 * - Most pure functional approach
 * - No global variables or parameters needed for sum
 * 
 * TC: O(n) - Makes n recursive calls
 * SC: O(n) - Recursion stack space
 */
int sumOfN_functional(int n) {
    // Base case: sum of 0 is 0
    if (n == 0) return 0;
    
    // Recursive call: current number + sum of remaining numbers
    return n + sumOfN_functional(n - 1);
}

// 🎯 Driver Function
int main() {
    int n;
    cout << "Enter a number N: ";
    cin >> n;
    
    // Approach 1: Parameterized Recursion
    cout << "\nApproach 1 - Parameterized Recursion:" << endl;
    sumOfN_param(n, 0);
    
    // Approach 2: Non-Parameterized Recursion
    cout << "\nApproach 2 - Non-Parameterized Recursion:" << endl;
    sum_nonparam = 0;  // Reset global variable
    sumOfN_nonparam(n);
    
    // Approach 3: Functional Recursion
    cout << "\nApproach 3 - Functional Recursion:" << endl;
    cout << "Functional Sum: " << sumOfN_functional(n) << endl;
    
    return 0;
}

/**
 * Additional Notes:
 * 1. All approaches have same time and space complexity
 * 2. Parameterized and Functional approaches are preferred as they:
 *    - Don't use global variables
 *    - Are more thread-safe
 *    - Can be called multiple times without side effects
 * 3. For very large N, consider using the mathematical formula: n*(n+1)/2
 *    which gives O(1) time and space complexity
 */
