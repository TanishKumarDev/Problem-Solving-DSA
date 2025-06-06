/**
 * Problem: Calculate the nth Fibonacci number and Fibonacci series
 * Fibonacci Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 * F(n) = F(n-1) + F(n-2) where F(0) = 0 and F(1) = 1
 * 
 * Approaches:
 * 1. Recursive Approach (Naive)
 * 2. Dynamic Programming (Memoization)
 * 3. Iterative Approach (Space Optimized)
 * 4. Matrix Exponentiation (Logarithmic)
 * 
 * Intuition:
 * - Each number is sum of previous two numbers
 * - Can be visualized as a tree of recursive calls
 * - Many overlapping subproblems in naive recursion
 * - Can be optimized using various techniques
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Naive Recursive Approach
 * - Simple but highly inefficient
 * - Recalculates same values multiple times
 * - Exponential time complexity
 * 
 * TC: O(2^n) - Exponential due to repeated calculations
 * SC: O(n) - Recursion stack space
 */
int fibonacciRecursive(int n) {
    // Base cases
    if(n <= 1) return n;
    
    // Recursive case: sum of previous two numbers
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

/**
 * Approach 2: Dynamic Programming with Memoization
 * - Uses array to store previously calculated values
 * - Avoids recalculating same values
 * - Much more efficient than naive recursion
 * 
 * TC: O(n) - Each value calculated only once
 * SC: O(n) - Array for memoization + recursion stack
 */
int fibonacciMemoization(int n, vector<int>& dp) {
    // Base cases
    if(n <= 1) return n;
    
    // Return memoized value if already calculated
    if(dp[n] != -1) return dp[n];
    
    // Calculate and store in dp array
    return dp[n] = fibonacciMemoization(n-1, dp) + fibonacciMemoization(n-2, dp);
}

/**
 * Approach 3: Iterative Approach (Space Optimized)
 * - Uses only two variables to store previous values
 * - Most space efficient
 * - No recursion overhead
 * 
 * TC: O(n) - Single loop
 * SC: O(1) - Constant space
 */
int fibonacciIterative(int n) {
    if(n <= 1) return n;
    
    int prev2 = 0, prev1 = 1;
    for(int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

/**
 * Approach 4: Matrix Exponentiation
 * - Uses matrix multiplication to calculate Fibonacci
 * - Most efficient for very large n
 * - Based on mathematical property of Fibonacci
 * 
 * TC: O(log n) - Logarithmic time
 * SC: O(1) - Constant space
 */
void multiply(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    
    F[0][0] = x; F[0][1] = y;
    F[1][0] = z; F[1][1] = w;
}

void power(int F[2][2], int n) {
    if(n <= 1) return;
    
    int M[2][2] = {{1,1}, {1,0}};
    power(F, n/2);
    multiply(F, F);
    
    if(n % 2 != 0) multiply(F, M);
}

int fibonacciMatrix(int n) {
    if(n <= 1) return n;
    
    int F[2][2] = {{1,1}, {1,0}};
    power(F, n-1);
    return F[0][0];
}

// Helper function to print Fibonacci series
void printFibonacciSeries(int n, function<int(int)> fibFunc) {
    cout << "Fibonacci series up to " << n << " terms: ";
    for(int i = 0; i < n; i++) {
        cout << fibFunc(i) << " ";
    }
    cout << endl;
}

// 🎯 Driver Function
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    // Approach 1: Naive Recursive (Warning: Very slow for n > 40)
    if(n <= 40) {
        cout << "\nApproach 1 - Naive Recursive:" << endl;
        cout << n << "th Fibonacci number is: " << fibonacciRecursive(n) << endl;
        printFibonacciSeries(n, fibonacciRecursive);
    }
    
    // Approach 2: Dynamic Programming
    cout << "\nApproach 2 - Dynamic Programming:" << endl;
    vector<int> dp(n + 1, -1);
    cout << n << "th Fibonacci number is: " << fibonacciMemoization(n, dp) << endl;
    printFibonacciSeries(n, [&dp](int i) { return fibonacciMemoization(i, dp); });
    
    // Approach 3: Iterative
    cout << "\nApproach 3 - Iterative:" << endl;
    cout << n << "th Fibonacci number is: " << fibonacciIterative(n) << endl;
    printFibonacciSeries(n, fibonacciIterative);
    
    // Approach 4: Matrix Exponentiation
    cout << "\nApproach 4 - Matrix Exponentiation:" << endl;
    cout << n << "th Fibonacci number is: " << fibonacciMatrix(n) << endl;
    printFibonacciSeries(n, fibonacciMatrix);
    
    return 0;
}

/**
 * Additional Notes:
 * 1. Performance Comparison:
 *    - Naive Recursive: O(2^n) - Only for small n (n ≤ 40)
 *    - Dynamic Programming: O(n) - Good for medium n
 *    - Iterative: O(n) - Best for most practical purposes
 *    - Matrix Exponentiation: O(log n) - Best for very large n
 * 
 * 2. Space Complexity:
 *    - Naive Recursive: O(n) - Stack space
 *    - Dynamic Programming: O(n) - Array + stack
 *    - Iterative: O(1) - Constant space
 *    - Matrix Exponentiation: O(1) - Constant space
 * 
 * 3. Edge Cases:
 *    - n = 0: returns 0
 *    - n = 1: returns 1
 *    - n < 0: should handle as invalid input (not implemented)
 * 
 * 4. Applications:
 *    - Golden ratio calculations
 *    - Computer algorithms
 *    - Financial modeling
 *    - Nature patterns (spiral arrangements)
 * 
 * 5. Interesting Properties:
 *    - Every 3rd Fibonacci number is even
 *    - Every 4th Fibonacci number is divisible by 3
 *    - GCD of two Fibonacci numbers is also a Fibonacci number
 */
