/**
 * Problem: Calculate factorial of a number N (N!)
 * Factorial of N = N * (N-1) * (N-2) * ... * 2 * 1
 * Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
 * 
 * Approaches:
 * 1. Recursive Approach
 * 2. Iterative Approach
 * 3. Parameterized Recursion
 * 
 * Intuition:
 * - Factorial can be broken down into smaller subproblems
 * - For N=5: 5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = ...
 * - Each recursive call handles one multiplication and delegates rest to next call
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Recursive Approach
 * - Uses return type to accumulate the result
 * - Most straightforward recursive implementation
 * 
 * TC: O(n) - Makes n recursive calls
 * SC: O(n) - Recursion stack space
 */
int factorial_recursive(int n) {
    // Base cases: 0! = 1! = 1
    if(n == 0 || n == 1) return 1;
    
    // Recursive case: n! = n * (n-1)!
    return n * factorial_recursive(n - 1);
}

/**
 * Approach 2: Iterative Approach
 * - Uses a loop instead of recursion
 * - More space efficient
 * 
 * TC: O(n) - Single loop runs n times
 * SC: O(1) - Constant space
 */
int factorial_iterative(int n) {
    int result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * Approach 3: Parameterized Recursion
 * - Passes the accumulated result as parameter
 * - More functional programming style
 * 
 * TC: O(n) - Makes n recursive calls
 * SC: O(n) - Recursion stack space
 */
void factorial_parameterized(int n, int result) {
    // Base case: when n becomes 0 or 1, print the result
    if(n == 0 || n == 1) {
        cout << "Parameterized Factorial: " << result << endl;
        return;
    }
    // Recursive call: multiply current result with n and decrement n
    factorial_parameterized(n - 1, result * n);
}

// 🎯 Driver Function
int main() {
    int n;
    cout << "Enter a number N: ";
    cin >> n;
    
    // Approach 1: Recursive
    cout << "\nApproach 1 - Recursive Factorial:" << endl;
    cout << "Recursive Factorial: " << factorial_recursive(n) << endl;
    
    // Approach 2: Iterative
    cout << "\nApproach 2 - Iterative Factorial:" << endl;
    cout << "Iterative Factorial: " << factorial_iterative(n) << endl;
    
    // Approach 3: Parameterized
    cout << "\nApproach 3 - Parameterized Factorial:" << endl;
    factorial_parameterized(n, 1);
    
    return 0;
}

/**
 * Additional Notes:
 * 1. For very large numbers, consider using:
 *    - Long long int or unsigned long long for larger range
 *    - Big integer libraries for very large factorials
 * 2. Factorial grows very quickly:
 *    - 10! = 3,628,800
 *    - 20! = 2,432,902,008,176,640,000
 * 3. Recursive vs Iterative:
 *    - Iterative is more space efficient (O(1) vs O(n))
 *    - Both have same time complexity O(n)
 *    - Recursive is more elegant but can cause stack overflow for large n
 * 4. Edge Cases:
 *    - n = 0: returns 1 (by definition)
 *    - n = 1: returns 1
 *    - n < 0: should handle as invalid input (not implemented here)
 */