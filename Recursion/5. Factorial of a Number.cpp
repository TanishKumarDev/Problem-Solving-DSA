#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Calculate factorial of a number N (N!)
 * Factorial of N = N * (N-1) * (N-2) * ... * 2 * 1
 * Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
 * 
 * Approaches:
 * 1. Recursive: N! = N * (N-1)!
 * 2. Iterative: Loop from 1 to N
 * 3. Parameterized Recursion: Accumulate result in parameter
 */

/**
 * Approach 1: Recursive Approach
 * - Uses return type to accumulate result
 * - TC: O(N) - N recursive calls
 * - SC: O(N) - Recursion stack space
 * 
 * @param n Input number
 * @return Factorial of n
 * 
 * Intuition:
 * - Base case: 0! = 1! = 1
 * - Recursive case: N! = N * (N-1)!
 * 
 */
long long factorial_recursive(int n) {
    if (n <= 1) return 1; // Base case: 0! = 1! = 1
    return n * factorial_recursive(n - 1); // Recursive case
}

/**
 * Approach 2: Iterative Approach
 * - Uses a loop, space-efficient
 * - TC: O(N) - Loop runs N times
 * - SC: O(1) - Constant space
 * 
 * 
 * @param n Input number
 * @return Factorial of n
 * 
 * Intuition:
 * - Loop from 1 to N, multiplying result by current number
 */
long long factorial_iterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * Approach 3: Parameterized Recursion
 * - Accumulates result in a parameter
 * - TC: O(N) - N recursive calls
 * - SC: O(N) - Recursion stack space
 * 
 * 
 * @param n Input number
 * @param result Accumulated result
 * @return Factorial of n
 *
 * Intuition:
 * - Base case: 0! = 1! = 1
 * - Recursive case: N! = N * (N-1)!
 */
long long factorial_parameterized(int n, long long result) {
    if (n <= 1) return result; // Base case
    return factorial_parameterized(n - 1, result * n); // Recursive case
}


int main() {
    int n;
    // cout << "Enter a number N: ";
    cin >> n;
    
    // Input validation
    if (n < 0) {
        cout << "Invalid input: N must be non-negative." << endl;
        return 0;
    }
    
    // Approach 1: Recursive
    cout << "Approach 1 - Recursive Factorial:" << endl;
    cout << "Factorial: " << factorial_recursive(n) << endl;
    
    // Approach 2: Iterative
    cout << "\nApproach 2 - Iterative Factorial:" << endl;
    cout << "Factorial: " << factorial_iterative(n) << endl;
    
    // Approach 3: Parameterized
    cout << "\nApproach 3 - Parameterized Factorial:" << endl;
    cout << "Factorial: " << factorial_parameterized(n, 1) << endl;
    
    return 0;
}
