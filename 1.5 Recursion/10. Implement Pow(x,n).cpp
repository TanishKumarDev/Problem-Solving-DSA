/**
 * @file Implement Pow(x,n).cpp
 * @brief Program to implement power function using different approaches
 * 
 * Problem: Implement pow(x, n) which calculates x raised to power n (x^n)
 * Examples: 
 * - pow(2.0, 10) = 1024.0
 * - pow(2.1, 3) = 9.261
 * - pow(2.0, -2) = 0.25
 * - pow(0.0, 0) = 1.0 (by definition)
 * 
 * Approaches:
 * 1. Naive Iterative Approach
 * 2. Binary Exponentiation (Fast Power)
 * 3. Recursive Binary Exponentiation
 * 
 * Intuition:
 * - For positive n: multiply x by itself n times
 * - For negative n: calculate x^(-n) and take reciprocal
 * - Binary exponentiation: use properties of exponents
 *   to reduce number of multiplications
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Naive Iterative Approach
 * - Simple but inefficient for large n
 * - Directly multiplies x by itself n times
 * - Handles negative exponents
 * 
 * TC: O(n) - Makes n multiplications
 * SC: O(1) - Constant space
 */
double powNaive(double x, int n) {
    // Handle edge cases
    if (n == 0) return 1.0;
    if (x == 0.0) return 0.0;
    
    double ans = 1.0;
    long long nn = abs((long long)n);  // handle large negatives safely
    
    // Multiply x by itself nn times
    for (int i = 0; i < nn; i++) {
        ans *= x;
    }
    
    return (n < 0) ? 1.0 / ans : ans;
}

/**
 * Approach 2: Binary Exponentiation (Iterative)
 * - Uses properties of exponents to reduce operations
 * - For even n: x^n = (x^2)^(n/2)
 * - For odd n: x^n = x * (x^2)^((n-1)/2)
 * - Much more efficient for large n
 * 
 * TC: O(log n) - Reduces multiplications to log n
 * SC: O(1) - Constant space
 */
double powBinaryIterative(double x, int n) {
    // Handle edge cases
    if (n == 0) return 1.0;
    if (x == 0.0) return 0.0;
    
    double ans = 1.0;
    long long nn = n;  // to avoid overflow
    if (nn < 0) nn = -nn;
    
    while (nn) {
        if (nn % 2) {      // odd power
            ans *= x;
            nn--;
        } else {           // even power
            x *= x;
            nn /= 2;
        }
    }
    
    return (n < 0) ? 1.0 / ans : ans;
}

/**
 * Approach 3: Recursive Binary Exponentiation
 * - Same mathematical approach as iterative
 * - More elegant but uses stack space
 * - Easier to understand the divide-and-conquer nature
 * 
 * TC: O(log n) - Reduces multiplications to log n
 * SC: O(log n) - Recursion stack space
 */
double powBinaryRecursive(double x, long long n) {
    // Handle edge cases
    if (x == 0.0) return 0.0;
    if (n == 0) return 1.0;
    
    // Handle negative power
    if (n < 0) {
        x = 1.0 / x;
        n = -n;
    }
    
    // Recursive cases
    if (n % 2 == 0) {  // even power
        return powBinaryRecursive(x * x, n / 2);
    } else {           // odd power
        return x * powBinaryRecursive(x * x, (n - 1) / 2);
    }
}

// Helper function to print power calculation
void printPower(double x, int n, double result) {
    cout << "pow(" << x << ", " << n << ") = " << result << endl;
}

// 🎯 Driver Function
int main() {
    try {
        // Test cases
        vector<pair<double, int>> testCases = {
            {2.0, 10},    // 1024.0
            {2.1, 3},     // 9.261
            {2.0, -2},    // 0.25
            {0.0, 0},     // 1.0
            {0.0, 5},     // 0.0
            {5.0, 0},     // 1.0
            {1.0, 1000},  // 1.0
            {2.0, -3}     // 0.125
        };
        
        // Test each approach
        cout << "Approach 1 - Naive Iterative:" << endl;
        for (const auto& test : testCases) {
            printPower(test.first, test.second, 
                      powNaive(test.first, test.second));
        }
        
        cout << "\nApproach 2 - Binary Exponentiation (Iterative):" << endl;
        for (const auto& test : testCases) {
            printPower(test.first, test.second, 
                      powBinaryIterative(test.first, test.second));
        }
        
        cout << "\nApproach 3 - Binary Exponentiation (Recursive):" << endl;
        for (const auto& test : testCases) {
            printPower(test.first, test.second, 
                      powBinaryRecursive(test.first, test.second));
        }
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

/**
 * Additional Notes:
 * 1. Edge Cases:
 *    - x = 0, n = 0: returns 1.0 (by definition)
 *    - x = 0, n > 0: returns 0.0
 *    - x = 0, n < 0: should handle as error (not implemented)
 *    - n = 0: returns 1.0 for any x
 *    - n = 1: returns x
 *    - n = -1: returns 1/x
 * 
 * 2. Performance Comparison:
 *    - Naive: O(n) time, O(1) space
 *    - Binary (both): O(log n) time
 *    - Binary Iterative: O(1) space
 *    - Binary Recursive: O(log n) space
 * 
 * 3. Mathematical Properties Used:
 *    - x^(a+b) = x^a * x^b
 *    - x^(a*b) = (x^a)^b
 *    - x^(-n) = 1/(x^n)
 * 
 * 4. Applications:
 *    - Scientific calculations
 *    - Cryptography
 *    - Computer graphics
 *    - Financial calculations
 * 
 * 5. Limitations:
 *    - Precision issues with floating-point
 *    - Overflow for very large exponents
 *    - Underflow for very small results
 * 
 * 6. Optimizations:
 *    - Use of long long to prevent overflow
 *    - Early returns for edge cases
 *    - Efficient handling of negative powers
 */
